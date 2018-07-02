#include <stdio.h>  
#include <unistd.h>  
#include <strings.h>  
#include <string.h>
#include <stdlib.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>
#include <netdb.h>  

#include <Pb.Ingenic.Sputnik.FrameResult.h>

#define DET_INFO_PORT 4000
#define PRASE_BUF_SIZE 4096*4*4
#define ITEMS_DEBUG_FILE "./file_debug_items.txt"

void assemble_format_data(int data_len, char *data_buf, char *buffer, int new_parse)
{
	static int nn = 0;
	if (new_parse)
		nn = 0;

	memcpy(buffer+nn, data_buf, data_len);
	nn += data_len;
}

int recv_data_from_sock(int sock_fd, int hdr_length, char *proto_data)
{
	int numbytes = 0, rs = 0;

	while(numbytes != hdr_length) {
		rs = recv(sock_fd, proto_data+numbytes, hdr_length-numbytes, 0);
		numbytes += rs;
	}

	return 0;
}
    
int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("Usage: %s ip\n", argv[0]);
		return -1;
	}

	char *server_ip = argv[1];

	int ret = -1;
	int sock_fd, numbytes;  
	char buf[1024];  
	char parse_buf[PRASE_BUF_SIZE];
	char proto_data[1024];
	struct sockaddr_in server;  

	sock_fd = socket(AF_INET, SOCK_STREAM, 0);  
	bzero(&server, sizeof(server));  
	server.sin_family = AF_INET;  
	server.sin_port = htons(DET_INFO_PORT);  
	server.sin_addr.s_addr = inet_addr(server_ip);  

	FILE *file_debug_items = NULL;
	file_debug_items = fopen(ITEMS_DEBUG_FILE, "w+");
	if (file_debug_items == NULL) {
		printf("open %s error!\n", ITEMS_DEBUG_FILE);
	}

        printf("Connecting for det.....\n");
	if (connect(sock_fd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1) {
		printf("connect error!\n");
	} else {
		printf("connect %s successful, start read data!\n", argv[1]);
		while(1) {
			int hdr_length = 10;
			int end_length = 6;

			memset(proto_data, 0x0, 1024);
			memset(parse_buf, 0x0, PRASE_BUF_SIZE);

			/* #1. read header */
			recv_data_from_sock(sock_fd, hdr_length, proto_data);

			assemble_format_data(strlen("FrameResult {\n"), "FrameResult {\n", parse_buf, 1);
			sprintf(buf, "\tHDR Name0 : %d\n", proto_data[0]);
			assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
			sprintf(buf, "\tHDR Name1 : %d\n", proto_data[1]);
			assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
			sprintf(buf, "\tHDR Name2 : %d\n", proto_data[2]);
			assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
			sprintf(buf, "\tHDR Versn : %d\n", proto_data[3]);
			assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
			sprintf(buf, "\tHDR Lengt : %d\n", ((unsigned short*)proto_data)[2]);
			assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
			sprintf(buf, "\tHDR NumRe : %d\n", ((unsigned short*)proto_data)[3]);
			assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
			sprintf(buf, "\tHDR HDCRC : %d\n", ((unsigned short*)proto_data)[4]);
			assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

			unsigned short length = ((unsigned short*)proto_data)[2];
			/* #2. read serializa protobuf data  */
			recv_data_from_sock(sock_fd, length, proto_data);

			/* #3. deserialize protobuf data */
			Pb_Ingenic_Sputnik_FrameResult_Data_Deserialize(proto_data);

			/* #4. get frame id */
			int frame_id = Pb_Ingenic_Sputnik_FrameResult_Get_Frame_ID();
			sprintf(buf, "\tHDR FRMID : %d\n", frame_id);
			assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

			/* #5. get version */
			char version[128];
			Pb_Ingenic_Sputnik_FrameResult_Get_Version(version);
			sprintf(buf, "\tHDR Versn : %s\n", version);
			assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

			/* #6. get items count */
			int items_cnt = Pb_Ingenic_Sputnik_FrameResult_Get_Items_Cnt();
			sprintf(buf, "\tHDR IMCNT : %d\n", items_cnt);
			assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

			int i = 0;
			for (i = 0; i < items_cnt; i++) {
				items_attr_t attr;
				/* #7. get items */
				Pb_Ingenic_Sputnik_FrameResult_Get_Items(i, &attr);

				sprintf(buf, "\titems %03d {\n", i);
				assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

				sprintf(buf, "\t\titems_type : %d\n", attr.items_type);
				assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

				if (attr.box.valid) {
					sprintf(buf, "\t\tBox {\n");
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

					sprintf(buf, "\t\t\titems box_x : %d\n", attr.box.x);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\titems box_y : %d\n", attr.box.y);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\titems box_w : %d\n", attr.box.w);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\titems box_h : %d\n", attr.box.h);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

					sprintf(buf, "\t\t}\n");
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
				}

				if (attr.items_type == 0) { //Face
					sprintf(buf, "\t\tFace Attr {\n");
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

					sprintf(buf, "\t\t\titems face blur : %d\n", attr.face_attr.blur);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\titems face age : %d\n", attr.face_attr.age);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\titems face gender : %d\n", attr.face_attr.gender);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\titems face pitch : %d\n", attr.face_attr.pitch);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\titems face yaw : %d\n", attr.face_attr.yaw);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\titems face roll : %d\n", attr.face_attr.roll);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\titems face post_filter_score : %d\n", attr.face_attr.post_filter_score);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\titems face minority : %d\n", attr.face_attr.minority);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

					sprintf(buf, "\t\t\tFace LandMark {\n");
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\t\tlefteye_pupil_x: %d\n", attr.face_attr.landmark.lefteye_pupil_x);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\t\tlefteye_pupil_y: %d\n", attr.face_attr.landmark.lefteye_pupil_y);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\t\trighteye_pupil_x: %d\n", attr.face_attr.landmark.righteye_pupil_x);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\t\trighteye_pupil_y: %d\n", attr.face_attr.landmark.righteye_pupil_y);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\t\tnose_tip_x: %d\n", attr.face_attr.landmark.nose_tip_x);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\t\tnose_tip_y: %d\n", attr.face_attr.landmark.nose_tip_y);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\t\tleft_mouth_corner_x: %d\n", attr.face_attr.landmark.left_mouth_corner_x);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\t\tleft_mouth_corner_y: %d\n", attr.face_attr.landmark.left_mouth_corner_y);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\t\tright_mouth_corner_x: %d\n", attr.face_attr.landmark.right_mouth_corner_x);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\t\tright_mouth_corner_y: %d\n", attr.face_attr.landmark.right_mouth_corner_y);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\t\tlefteye_right_corner_x: %d\n", attr.face_attr.landmark.lefteye_right_corner_x);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\t\tlefteye_right_corner_y: %d\n", attr.face_attr.landmark.lefteye_right_corner_y);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\t\trighteye_left_corner_x: %d\n", attr.face_attr.landmark.righteye_left_corner_x);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\t\trighteye_left_corner_y: %d\n", attr.face_attr.landmark.righteye_left_corner_y);
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
					sprintf(buf, "\t\t\t}\n");
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

					sprintf(buf, "\t\t}\n");
					assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
				}

				sprintf(buf, "\t\titems_video_channel_id : %d\n", attr.items_video_channel_id);
				assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

				sprintf(buf, "\t\titems_frame_id : %d\n", attr.items_frame_id);
				assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

				sprintf(buf, "\t\titems_track_id : %d\n", attr.items_track_id);
				assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

				sprintf(buf, "\t\titems_track_update : %d\n", attr.items_track_update);
				assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

				sprintf(buf, "\t\titems_track_die : %d\n", attr.items_track_die);
				assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

				sprintf(buf, "\t\titems_track_show : %d\n", attr.items_track_show);
				assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

				sprintf(buf, "\t\titems_track_push : %d\n", attr.items_track_push);
				assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

				sprintf(buf, "\t\titems_timestamp_millis : %lld\n", attr.items_timestamp_millis);
				assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

				sprintf(buf, "\t}\n");
				assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
			}

			recv_data_from_sock(sock_fd, end_length, proto_data);
			sprintf(buf, "\tEND PLCRC : %d\n", ((unsigned short*)proto_data)[0]);
			assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
			sprintf(buf, "\tEND NAME0 : %c\n", proto_data[2]);
			assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
			sprintf(buf, "\tEND NAME1 : %c\n", proto_data[3]);
			assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
			sprintf(buf, "\tEND NAME2 : %c\n", proto_data[4]);
			assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);
			sprintf(buf, "\tEND PROVS : %c\n\n", proto_data[5]);
			assemble_format_data(strlen(buf), buf, parse_buf, 0); memset(buf, 0x0, 1024);

			assemble_format_data(strlen("}\n"), "}\n", parse_buf, 0); memset(buf, 0x0, 1024);
			if (file_debug_items) {
				fwrite(parse_buf, strlen(parse_buf), 1, file_debug_items);
			}
		}
	}

	return 0;
}

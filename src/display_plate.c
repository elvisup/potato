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
	char proto_data[1024];
	struct sockaddr_in server;  

	sock_fd = socket(AF_INET, SOCK_STREAM, 0);  
	bzero(&server, sizeof(server));  
	server.sin_family = AF_INET;  
	server.sin_port = htons(DET_INFO_PORT);  
	server.sin_addr.s_addr = inet_addr(server_ip);  

        printf("Connecting for det.....\n");
	if (connect(sock_fd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1) {
		printf("connect error!\n");
	} else {
		printf("connect %s successful, start read data!\n", argv[1]);
		while(1) {
			int hdr_length = 10;
			int end_length = 6;

			memset(proto_data, 0x0, 1024);
			recv_data_from_sock(sock_fd, hdr_length, proto_data);
			printf("==========\n");
			printf("\tHDR Name0 : %d\n", proto_data[0]);
			printf("\tHDR Name1 : %d\n", proto_data[1]);
			printf("\tHDR Name2 : %d\n", proto_data[2]);
			printf("\tHDR Versn : %d\n", proto_data[3]);
			printf("\tHDR Lengt : %d\n", ((unsigned short*)proto_data)[2]);
			printf("\tHDR NumRe : %d\n", ((unsigned short*)proto_data)[3]);
			printf("\tHDR HDCRC : %d\n", ((unsigned short*)proto_data)[4]);

			unsigned short length = ((unsigned short*)proto_data)[2];
			recv_data_from_sock(sock_fd, length, proto_data);

			Pb_Ingenic_Sputnik_FrameResult_Data_Deserialize(proto_data);
			int frame_id = Pb_Ingenic_Sputnik_FrameResult_Get_Frame_ID();
			char version[128];
			Pb_Ingenic_Sputnik_FrameResult_Get_Version(version);
			int items_cnt = Pb_Ingenic_Sputnik_FrameResult_Get_Items_Cnt();
			printf("\tHDR FRMID : %d\n", frame_id);
			printf("\tHDR Versn : %s\n", version);
			printf("\tHDR IMCNT : %d\n", items_cnt);

			int i = 0;
			for (i = 0; i < items_cnt; i++) {
				items_attr_t attr;
				Pb_Ingenic_Sputnik_FrameResult_Get_Items(i, &attr);
				printf("\t+++++++++++\n");
				printf("\t\titems_type : %d\n", attr.items_type);
				printf("\t\titems_video_channel_id : %d\n", attr.items_video_channel_id);
				printf("\t\titems_frame_id : %d\n", attr.items_frame_id);
				printf("\t\titems_track_id : %d\n", attr.items_track_id);
				printf("\t\titems_track_update : %d\n", attr.items_track_update);
				printf("\t\titems_track_die : %d\n", attr.items_track_die);
				printf("\t\titems_track_show : %d\n", attr.items_track_show);
				printf("\t\titems_track_push : %d\n", attr.items_track_push);
				printf("\t\titems_timestamp_millis : %lld\n", attr.items_timestamp_millis);
			}

			recv_data_from_sock(sock_fd, end_length, proto_data);
		}
	}

	return 0;
}

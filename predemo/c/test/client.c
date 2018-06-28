#include <stdio.h>  
#include <unistd.h>  
#include <strings.h>  
#include <stdlib.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <netdb.h>  
#include "../out/include/Pb.Ingenic.Potato.Demo.People.h"  

#define HOST "localhost"  
#define PORT 8888  
#define MAXDATASIZE 100  

/*using namespace std;  */

int main(int argc, char ** argv)  
{  
	int ret = -1;
	int fd, numbytes;  
	char buf[MAXDATASIZE];  
	struct hostent *he;  
	struct sockaddr_in server;  

	if (argc != 2) {  
		printf("Usage: %s \"COMMAND\"\n",argv[0]);  
		exit(0);  
	}   

	he = gethostbyname(HOST);  
	fd = socket(AF_INET, SOCK_STREAM, 0);  
	bzero(&server, sizeof(server));  
	server.sin_family = AF_INET;  
	server.sin_port = htons(PORT);  
	server.sin_addr = *((struct in_addr *)he->h_addr);  

	connect(fd, (struct sockaddr *)&server, sizeof(struct sockaddr));  

	send(fd, argv[1], 20, 0);  

	numbytes = recv(fd, buf, MAXDATASIZE, 0);  
	buf[numbytes] = '\0';  
	char *data = buf;

	char name[16];
	char mail[48];
	ret = Pb_Ingenic_Potato_Demo_People_Data_Deserialize(data);
	ret = Pb_Ingenic_Potato_Demo_People_Get_Name(name);
	int id = Pb_Ingenic_Potato_Demo_People_Get_ID();
	ret = Pb_Ingenic_Potato_Demo_People_Get_Mail(mail);

	printf("People:\n");  
	printf("Name: %s\n", name);  
	printf("ID: %d\n", id);  
	printf("Email: %s\n", mail);  

	int attr_cnt = Pb_Ingenic_Potato_Demo_People_Get_PAttr_Cnt();

	int i = 0, age, gender;
	for (i = 0; i < attr_cnt; i++) {
		ret = Pb_Ingenic_Potato_Demo_People_Get_PAttr(i, &age, &gender);
		printf("attr%02d age: %d\n", i, age);
		printf("attr%02d gender: %d\n", i, gender);
	}

#if 0
	ofstream ofile;
	ofile.open("./client_recv_file.txt");
	ofile<< buf <<endl;
	ofile.close();
#endif

	close(fd);  
	return 0;  
}  

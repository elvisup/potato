#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../out/include/Pb.Ingenic.Potato.Demo.People.h"  

#define PORT 8888
#define MAXDATASIZE 20
#define BACKLOG 10

int main()
{
	int listenfd, connectfd, numbytes;
	char buf[MAXDATASIZE];
	struct sockaddr_in server;
	struct sockaddr_in client;
	int sin_size;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	int opt = SO_REUSEADDR;
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(listenfd, (struct sockaddr *)&server, sizeof(struct sockaddr));

	listen(listenfd,BACKLOG);

	int ret = -1;
	char serialize_data[1024] = {0};
	while(1){
		sin_size = sizeof(struct sockaddr_in);

		connectfd = accept(listenfd, (struct sockaddr *)&client, (socklen_t*)&sin_size);

		numbytes = recv(connectfd, buf, MAXDATASIZE, 0);
		buf[numbytes] = '\0';
		char* a = buf;
		printf("You got a message from: %s\n", inet_ntoa(client.sin_addr));
		printf("Client Message: %s\n", a);
		if(!strcmp(a, "GET PEOPLE")) {
			ret = Pb_Ingenic_Potato_Demo_People_Set_Name("WYB");
			ret = Pb_Ingenic_Potato_Demo_People_Set_ID(2018);
			ret = Pb_Ingenic_Potato_Demo_People_Set_Mail("wyb@xxx.com");
			ret = Pb_Ingenic_Potato_Demo_People_Add_New_PAttr(120, 100);
			ret = Pb_Ingenic_Potato_Demo_People_Data_Serialize(serialize_data);
			send(connectfd, serialize_data, sizeof(serialize_data), 0);
		} else {
			send(connectfd, "Fucking client!\n", 16, 0);
		}
		close(connectfd);
	}
	close(listenfd);

	return 0;
}


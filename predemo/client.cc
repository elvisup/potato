#include <stdio.h>  
#include <unistd.h>  
#include <strings.h>  
#include <stdlib.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <netdb.h>  
#include <string>  
#include <fstream>
#include <iostream>  
#include "pb_dst/Ingenic.Potato.Demo.People.pb.h"  

#define HOST "localhost"  
#define PORT 8888  
#define MAXDATASIZE 100  

using namespace std;  

int main(int argc, char ** argv)  
{  
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
	string data = buf;  
	demo::People p;  

	p.ParseFromString(data);  
	cout << p.people_attr_size() << endl;
	demo::People::PAttr pattr = p.people_attr(0);

	demo::Oftest0 *oft_0 = p.mutable_test0();

	cout << "People: " << endl;  
	cout << "Name: " << p.name() << endl;  
	cout << "ID: " << p.id() << endl;  
	cout << "Email: " << p.email() << endl;  
	cout << "age: " << pattr.age() << endl;
	cout << "genger: " << pattr.gender() << endl;
	cout << "has test0: " << p.has_test0() << endl;
	cout << "has test1: " << p.has_test1() << endl;
	cout << "oka: " << oft_0->oka() << endl;
	cout << "okb: " << oft_0->okb() << endl;
	cout << "data: " << p.data() << endl;

#if 0
	ofstream ofile;
	ofile.open("./client_recv_file.txt");
	ofile<< buf <<endl;
	ofile.close();
#endif

	close(fd);  
	return 0;  
}  

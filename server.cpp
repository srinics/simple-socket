#include <iostream>
#include<cstdio>
#include<cstring>
#include "socket-connection.h"


void * get_in_addr(struct sockaddr * sa)
{
	if (sa->sa_family == AF_INET)
	{
		return &(((struct sockaddr_in *)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6 *)sa)->sin6_addr);
}


int main(int argc, char * argv[])
{
	int status=-1;
	struct addrinfo hints, *res;
	int listner;

	// Before using hint you have to make sure that the data structure is empty 
	memset(&hints, 0, sizeof hints);
	// Set the attribute for hint
	hints.ai_family = AF_INET; // We don't care V4 AF_INET or 6 AF_INET6
	hints.ai_socktype = SOCK_STREAM; // TCP Socket SOCK_DGRAM 
	hints.ai_flags = AI_PASSIVE;

	

	// Create Socket and check if error occured afterwards
	listner = CreateSocket(AF_INET, SOCK_STREAM, 0);
	//listner = CreateSocket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (listner < 0)
	{
		fprintf(stderr, "socket error: %s\n", gai_strerror(status));
	}
	// Fill the res data structure and make sure that the results make sense. 
	status = getaddrinfo(NULL, "8888", &hints, &res);
	if (status != 0)
	{
		fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
		return -1;
	}

	// Bind the socket to the address of my local machine and port number 
	status = bind(listner, res->ai_addr, res->ai_addrlen);
	if (status < 0)
	{
		fprintf(stderr, "bind: %s\n", gai_strerror(status));
		return -1;
	}

	status = listen(listner, 10);
	if (status < 0)
	{
		fprintf(stderr, "listen: %s\n", gai_strerror(status));
		return -1;
	}

	// Free the res linked list after we are done with it	
	freeaddrinfo(res);


	// We should wait now for a connection to accept
	int new_conn_fd;
	struct sockaddr_storage client_addr;
	socklen_t addr_size;
	char s[INET6_ADDRSTRLEN]; // an empty string 

	// Calculate the size of the data structure	
	addr_size = sizeof client_addr;

	printf("I am now accepting connections ...\n");

	while (1) {
		// Accept a new connection and return back the socket desciptor 
		new_conn_fd = accept(listner, (struct sockaddr *) & client_addr, &addr_size);
		if (new_conn_fd < 0)
		{
			fprintf(stderr, "accept: %s\n", gai_strerror(new_conn_fd));
			continue;
		}

		inet_ntop(client_addr.ss_family, get_in_addr((struct sockaddr *) &client_addr), s, sizeof s);
		printf("I am now connected to %s \n", s);
		status = send(new_conn_fd, "Welcome", 7, 0);
		if (status == -1)
		{
			CloseSocket(new_conn_fd);
			_exit(4);
		}

	}
	// Close the socket before we finish 
	CloseSocket(new_conn_fd);
	return 0;
}

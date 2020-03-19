/*
Author: M1043833 ( Srinivasan Rajendran )
Description: This file contains function for getting Windows Create TCP/UDP Socket ( CreateSocket ) and
function for closing the socket connection
*/

#include "stdafx.h"
#include <iostream>
#include <stdexcept>
#include "socket-connection.h"

using namespace std;


/*
Author: M1043833
Function Name: CreateSocket
Description:
Function used for creating the socket and it is wrapper function for socket api and it wil take three
arguements family either AF_INET/PF_INET, stream SOCK_STREAM/SOCK_DGRAM and protocol if any. And default values
for family, stream, protocol are AF_INET, SOCK_STREAM, 0 respectively
*/
int CreateSocket(int family = AF_INET, int stream = SOCK_STREAM, int protocol = 0){
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {
		throw std::runtime_error("WSA Startup failed");
	}

	int sd = socket(family, stream, protocol);
	if (sd < 0)
	{
		throw std::runtime_error("Socket Creation Failed");
	}

	std::cout << "Socket created Successfully..." << std::endl;
	return sd;
}


/*
Author: M1043833
Function Name: CloseSocket
Description:
Function used for closing socket.
*/
void CloseSocket(int sd){
	if (sd < 0){
		throw std::runtime_error("Invalid Socket SD");
	}
	closesocket(sd);
	WSACleanup();
}


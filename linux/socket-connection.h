#ifndef __SOCKET_CONNECTION_H__
#define __SOCKET_CONNECTION_H__

#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>
#include<arpa/inet.h>

int CreateSocket(int family, int stream, int protocol);
void CloseSocket(int sd);

#endif

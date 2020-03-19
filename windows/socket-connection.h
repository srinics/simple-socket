#ifndef __SOCKET_CONNECTION_H__
#define __SOCKET_CONNECTION_H__

#include <winsock2.h>
#include <ws2tcpip.h>

int CreateSocket(int family, int stream, int protocol);
void CloseSocket(int sd);

#endif

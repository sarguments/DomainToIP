#pragma once

#pragma comment(lib, "ws2_32")
#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <atlsocket.h>

class CNetLib
{
public:
	CNetLib();
	~CNetLib();

	// TODO : private 여부는 나중에
	SOCKET _listenSock;

private:
	
};
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

	// TODO : private ���δ� ���߿�
	SOCKET _listenSock;

private:
	
};
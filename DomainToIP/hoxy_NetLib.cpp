#include "stdafx.h"
#include "hoxy_NetLib.h"
#include "hoxy_CmdStart.h"



CNetLib::CNetLib()
	: _listenSock(INVALID_SOCKET)
{
	WSADATA wsa;
	int ret = WSAStartup(MAKEWORD(2, 2), &wsa);
	if (ret != 0)
	{
		CCmdStart::CmdDebugText(L"WinSock Init", false);
	}

	CCmdStart::CmdDebugText(L"WinSock Init", true);
}

CNetLib::~CNetLib()
{
	WSACleanup();
}
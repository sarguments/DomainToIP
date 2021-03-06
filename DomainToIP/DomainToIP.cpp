#include "stdafx.h"

#include "hoxy_CmdStart.h"
#include "hoxy_NetLib.h"

BOOL DomainToIP(WCHAR* szDomain, IN_ADDR* pAddr)
{
	ADDRINFOW* pAddrInfo;
	SOCKADDR_IN* pSockAddr;
	if (GetAddrInfo(szDomain, L"0", NULL, &pAddrInfo) != 0)
	{
		return FALSE;
	}
	pSockAddr = (SOCKADDR_IN*)pAddrInfo->ai_addr;
	*pAddr = pSockAddr->sin_addr;
	FreeAddrInfo(pAddrInfo);
	return TRUE;
}

// 백로그
// 에코

int main()
{
	CCmdStart CmdStart;
	CNetLib CNetLib;

	CCmdStart::CmdDebugText(L"Main start", true);

	// http는 프로토콜
	WCHAR myAddress[] = L"www.daum.net";
	IN_ADDR toGetAddr;
	ZeroMemory(&toGetAddr, sizeof(IN_ADDR));

	SOCKADDR_IN mySockAddr;
	ZeroMemory(&mySockAddr, sizeof(SOCKADDR_IN));

	DomainToIP(myAddress, &toGetAddr);

	mySockAddr.sin_family = AF_INET;
	mySockAddr.sin_port = htons(80);
	mySockAddr.sin_addr = toGetAddr;

	WCHAR toGetIP[16] = { 0, };
	// 그냥 mySockAddr 이 아님
	InetNtop(AF_INET, &mySockAddr.sin_addr, toGetIP, 16);

	wcout << toGetIP << endl;

	return 0;
}
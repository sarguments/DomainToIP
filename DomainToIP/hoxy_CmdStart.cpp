#include "stdafx.h"
#include "hoxy_CmdStart.h"

CCmdStart::CCmdStart()
{
	_wsetlocale(LC_ALL, L"korean");
	CCmdStart::CmdDebugText(L"Locale Init", true);

	//// 콘솔 창 띄우기
	//AllocConsole();
	//FILE *acStreamOut;
	//freopen_s(&acStreamOut, "CONOUT$", "wt", stdout);
	//wcout << L"Consol Window 초기화" << std::setw(30) << L"|OK|" << endl;
}

CCmdStart::~CCmdStart()
{
	_wsetlocale(LC_ALL, L"");
}

void CCmdStart::CmdDebugText(WCHAR* text, bool bParam)
{
	if (bParam)
	{
		wcout << std::setw(20) << text << std::setw(30) << L"|OK|" << endl;
	}
	else
	{
		wcout << std::setw(20) << text << std::setw(30) << L"|ERROR|" << endl;
	}
}
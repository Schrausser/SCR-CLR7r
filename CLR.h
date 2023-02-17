
#if !defined(AFX_CLR_H__9D2ED6FA_E526_4083_BA98_94441F4270D6__INCLUDED_)
#define AFX_CLR_H__9D2ED6FA_E526_4083_BA98_94441F4270D6__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"	


class CCLRApp : public CWinApp
{
	public:
	CCLRApp();

	public:
	virtual BOOL InitInstance();
	DECLARE_MESSAGE_MAP()
};


#endif 


// dung.h : main header file for the dung application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CdungApp:
// See dung.cpp for the implementation of this class
//

class CdungApp : public CWinApp
{
public:
	CdungApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CdungApp theApp;

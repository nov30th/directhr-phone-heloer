
// vincent_qiu_softphone_luncher.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cvincent_qiu_softphone_luncherApp:
// �йش����ʵ�֣������ vincent_qiu_softphone_luncher.cpp
//

class Cvincent_qiu_softphone_luncherApp : public CWinApp
{
public:
	Cvincent_qiu_softphone_luncherApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cvincent_qiu_softphone_luncherApp theApp;
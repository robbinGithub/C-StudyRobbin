
// MFCӦ�ó���̬����dll��Ŀ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCӦ�ó���̬����dll��ĿApp: 
// �йش����ʵ�֣������ MFCӦ�ó���̬����dll��Ŀ.cpp
//

class CMFCӦ�ó���̬����dll��ĿApp : public CWinApp
{
public:
	CMFCӦ�ó���̬����dll��ĿApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCӦ�ó���̬����dll��ĿApp theApp;
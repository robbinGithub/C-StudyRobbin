
// MFC应用程序动态加载dll项目.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CMFC应用程序动态加载dll项目App: 
// 有关此类的实现，请参阅 MFC应用程序动态加载dll项目.cpp
//

class CMFC应用程序动态加载dll项目App : public CWinApp
{
public:
	CMFC应用程序动态加载dll项目App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMFC应用程序动态加载dll项目App theApp;
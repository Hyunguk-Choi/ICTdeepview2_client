
// OpenCV302Server.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// COpenCV302ServerApp:
// �� Ŭ������ ������ ���ؼ��� OpenCV302Server.cpp�� �����Ͻʽÿ�.
//

class COpenCV302ServerApp : public CWinApp
{
public:
	COpenCV302ServerApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern COpenCV302ServerApp theApp;
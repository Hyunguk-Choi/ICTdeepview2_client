
// OpenCV302ServerDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "OpenCV320Client.h"
#include "OpenCV320ClientDlg.h"
#include "afxdialogex.h"

//#include "Common/streamingreceiver.h"
#include "Common/streamingsender.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COpenCV302ServerDlg ��ȭ ����



COpenCV302ServerDlg::COpenCV302ServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OPENCV302SERVER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpenCV302ServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COpenCV302ServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &COpenCV302ServerDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// COpenCV302ServerDlg �޽��� ó����

BOOL COpenCV302ServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void COpenCV302ServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void COpenCV302ServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR COpenCV302ServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COpenCV302ServerDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//cvproc::cStreamingReceiver streamRcv;
	//if (!streamRcv.Init(false, 12001))
	//{
	//	//cout << "Camera Streaming Error!!!" << endl;
	//}
	//else
	//{
	//	//cout << "Camera Streaming Success" << endl;
	//}

	// Streaming  Client
	cvproc::cStreamingSender streamSender;
	cvproc::ICT_META_DATA metaData;
	if (!streamSender.Init(false, "59.20.89.51", 8891, false, true))
	{
		//AfxMessageBox(L"Camera Streaming Init Error!!!");
		std::cout << "Camera Streaming Init Error!!!" << std::endl;
	}
	else
	{
		//AfxMessageBox(L"Camera Streaming Init Success");
		std::cout << "Camera Streaming Init Success" << std::endl;
	}

	//const string windowName = "Camera Streaming Receiver";
	const string windowName = "Client";
	namedWindow(windowName);

	while (1)
	{
		//imshow(windowName, streamRcv.Update());
		imshow(windowName, streamSender.Update(&metaData));

		if (metaData.CameraNumber > 0) {
			CString msg;
			msg.Format(L"CameraNum : %d\n FrameNum : %d\n ObjectNum : %d\n TechnologyType : %d", metaData.CameraNumber, metaData.FrameNumber, metaData.NumberOfObject, metaData.TechnologyType);
			SetDlgItemText(IDC_STATIC_META, msg);
			msg.Format(L"x : %d\n y : %d\n w : %d\n h : %d", metaData.pObjectData[0].x, metaData.pObjectData[0].y, metaData.pObjectData[0].Width, metaData.pObjectData[0].Height);
			SetDlgItemText(IDC_STATIC_META2, msg);
		}		

		const int key = cvWaitKey(1);
		if (key == VK_ESCAPE)
			break;
	}

	CDialogEx::OnOK();
}

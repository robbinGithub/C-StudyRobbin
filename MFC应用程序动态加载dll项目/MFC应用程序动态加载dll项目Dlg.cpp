
// MFCӦ�ó���̬����dll��ĿDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCӦ�ó���̬����dll��Ŀ.h"
#include "MFCӦ�ó���̬����dll��ĿDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCӦ�ó���̬����dll��ĿDlg �Ի���



CMFCӦ�ó���̬����dll��ĿDlg::CMFCӦ�ó���̬����dll��ĿDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCӦ�ó���̬����dll��ĿDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCӦ�ó���̬����dll��ĿDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCӦ�ó���̬����dll��ĿDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCӦ�ó���̬����dll��ĿDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCӦ�ó���̬����dll��ĿDlg ��Ϣ�������

BOOL CMFCӦ�ó���̬����dll��ĿDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCӦ�ó���̬����dll��ĿDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCӦ�ó���̬����dll��ĿDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCӦ�ó���̬����dll��ĿDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//�ͻ��˳�ʼ�� ��ȡhandle����
typedef int(*CltSocketInit)(void **handle);
//�ͻ��˷�����
typedef int(*CltSocketSend)(void *handle, unsigned char *buf, int buflen);
//�ͻ����ձ���
typedef int(*CltSocketRev)(void *handle, unsigned char *buf, int *buflen);

//�ͻ����ͷ���Դ
typedef int(*CltSocketDestory)(void *handle);


void CMFCӦ�ó���̬����dll��ĿDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HINSTANCE hInstance = NULL;
	hInstance = ::LoadLibrary("c:/socketclient.dll");
	CltSocketInit cltSocketInit = (CltSocketInit)::GetProcAddress(hInstance, "cltSocketInit");
	CltSocketSend cltSocketSend = (CltSocketSend)::GetProcAddress(hInstance, "cltSocketSend");
	CltSocketRev cltSocketRev = (CltSocketRev)::GetProcAddress(hInstance, "cltSocketRev");
	CltSocketDestory cltSocketDestory = (CltSocketDestory)::GetProcAddress(hInstance, "cltSocketDestory");

	void *handle = NULL;
	unsigned char buf[100];
	int buflen = 10;
	memcpy(buf, "ddddddddddssssssssss", 10);

	unsigned char out[100] = { 0 };
	int outlen = 0;

	int ret = cltSocketInit(&handle);

	ret = cltSocketSend(handle, buf, buflen);
	ret = cltSocketRev(handle, out, &outlen);
	ret = cltSocketDestory(handle);

	printf("out:%s", out);
	AfxMessageBox("dddddddddddddddddd");


}

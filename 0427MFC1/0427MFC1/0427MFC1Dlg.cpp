
// 0427MFC1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "0427MFC1.h"
#include "0427MFC1Dlg.h"
#include "afxdialogex.h"
#include<fstream>
#include <iostream>
#include<string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMy0427MFC1Dlg �Ի���



CMy0427MFC1Dlg::CMy0427MFC1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY0427MFC1_DIALOG, pParent)
	, sname(_T(""))
	, count(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


CMy0427MFC1Dlg::~CMy0427MFC1Dlg()
{
	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	ofstream ofs(_T("C:\\Users\\18045\\Documents\\ѧ������.txt"));
	for (int i = 0; i < count; i++)
	{
		ofs << CT2A(ca[i].GetString()) << endl;
	}
}

void CMy0427MFC1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, LBox);
	DDX_Text(pDX, IDC_EDIT1, sname);
}

BEGIN_MESSAGE_MAP(CMy0427MFC1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON1, &CMy0427MFC1Dlg::OnBnClickedButton1)
ON_LBN_SELCHANGE(IDC_LIST1, &CMy0427MFC1Dlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// CMy0427MFC1Dlg ��Ϣ�������

BOOL CMy0427MFC1Dlg::OnInitDialog()
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

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	string s;
	ifstream ifs(_T("C:\\Users\\18045\\Documents\\ѧ������.txt"));
	ca.SetSize(100);                           //���鱣���б�������
	int i = 0;
	while (ifs >> s)
	{
		LBox.InsertString(-1,CString(s.c_str()) );
		ca.SetAt(i++, CString(s.c_str()));
	}
	count = LBox.GetCount();
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy0427MFC1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy0427MFC1Dlg::OnPaint()
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
HCURSOR CMy0427MFC1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy0427MFC1Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	int n = LBox.GetCurSel();
	LBox.InsertString(n,sname);
	LBox.DeleteString(n+1);
	ca.InsertAt(n,sname);
	ca.RemoveAt(n+1);
}


void CMy0427MFC1Dlg::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	LBox.GetText(LBox.GetCurSel(), sname);
	SetDlgItemText(IDC_EDIT1, sname);
}

// MyDlg1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "0421MFC.h"
#include "MyDlg1.h"
#include "afxdialogex.h"

#include<fstream>
#include<iostream>
#include<string>
using namespace std;

// MyDlg1 �Ի���

IMPLEMENT_DYNAMIC(MyDlg1, CDialogEx)

MyDlg1::MyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlg1::~MyDlg1()
{
}

void MyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlg1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg1::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg1 ��Ϣ�������


void MyDlg1::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

		ifstream ifs(_T("C:\\Users\\18045\\Documents\\abc.txt"));
		string s;
		ifs >> s;                          //��ȡabc.txt�ļ�  �����ļ����ݣ�����������jpg�ļ�·����д�뵽s

		CImage img;
		img.Load(CString(s.c_str()));
		if (!img.IsNull())
		{
			int sx, sy, w, h;
			foo(img, sx, sy, w, h);
			//CString ss;
			//ss.Format(_T("x=%d,,y=%d"), sx, sy);
			CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
			pDC->SetStretchBltMode(HALFTONE);      //ͼ��ʧ��
			img.Draw(pDC->m_hDC, sx, sy, w, h);// 0, 0, img.GetWidth(), img.GetHeight());//
			ReleaseDC(pDC);
		}
		else
		{
			MessageBox(_T("Load Error"));
		}


}


void MyDlg1::foo(CImage &img, int &sx, int &sy, int &w, int &h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);            //ȡ�ÿͻ���
	float rect_ratio = 1.0*rect.Width() / rect.Height();     //����ͻ����Ŀ�߱�
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();   //����ͼƬ�Ŀ�߱�
	if (rect_ratio > img_ratio)                             //����ͻ�����߱ȸ���ͬ���߶�ʱͼƬ�ؼ�����
	{
		h = rect.Height();                                 //�Կͻ����߶�Ϊ�߶�
		w = img_ratio*h;                                   //����������ͼƬ�Ŀ��
		sx = (rect.Width() - w) / 2;                      //���Ͻ��������
		sy = 0;                                          //����ڿͻ�������   y=0
	}
	else
	{
		w = rect.Width();                             //�Կͻ������Ϊ���
		h = w / img_ratio;                             //����������ͼƬ�ĸ߶�
		sx = 0;                                     //����ڿͻ�������   x=0
		sy = (rect.Height() - h) / 2;                //���Ͻ��������
	}

}


// 0421MFCView.cpp : CMy0421MFCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0421MFC.h"
#endif

#include "0421MFCDoc.h"
#include "0421MFCView.h"
#include "MyDlg1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include<fstream>
#include<iostream>
#include<string>
using namespace std;

// CMy0421MFCView

IMPLEMENT_DYNCREATE(CMy0421MFCView, CView)

BEGIN_MESSAGE_MAP(CMy0421MFCView, CView)
	ON_COMMAND(ID_Save, &CMy0421MFCView::OnSave)
	ON_COMMAND(ID_Show, &CMy0421MFCView::OnShow)
END_MESSAGE_MAP()

// CMy0421MFCView ����/����

CMy0421MFCView::CMy0421MFCView()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0421MFCView::~CMy0421MFCView()
{
}

BOOL CMy0421MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0421MFCView ����

void CMy0421MFCView::OnDraw(CDC* pDC)
{
	CMy0421MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s1, s2;
	s1 = "���  �˵�-����·��������CFileDialog,ѡ��һ��jpg�ļ�������·������abc.txt�ļ��С�";
	s2 = "���  �˵�-��ʾͼƬ�������Ի��򣬵����ʾͼƬ��ť����ȡabc.txt�ļ�, �õ�jpg�ļ���·������Ȼ���ڶԻ����ϵ�ͼƬ�ؼ��Ͼ�����ʾ��ͼ��";
	pDC->TextOutW(100, 70, s1);
	pDC->TextOutW(100, 100, s2);

}


// CMy0421MFCView ���

#ifdef _DEBUG
void CMy0421MFCView::AssertValid() const
{
	CView::AssertValid();
}

void CMy0421MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0421MFCDoc* CMy0421MFCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0421MFCDoc)));
	return (CMy0421MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy0421MFCView ��Ϣ�������


void CMy0421MFCView::OnSave()
{
	// TODO: �ڴ���������������

	CFileDialog cfd(true);
	int r = cfd.DoModal();                        //�����ļ�����
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();       //��ȡjpg�ļ���·�������浽filename
		ofstream ofs(_T("C:\\Users\\18045\\Documents\\abc.txt"));
		ofs << CT2A(filename.GetString()) << endl;       //��filenameת�������abc.txt�ļ���
	}
}


void CMy0421MFCView::OnShow()
{
	// TODO: �ڴ���������������
	MyDlg1 dlg;
	dlg.DoModal();
}

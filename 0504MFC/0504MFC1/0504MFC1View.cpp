
// 0504MFC1View.cpp : CMy0504MFC1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0504MFC1.h"
#endif

#include "0504MFC1Doc.h"
#include "0504MFC1View.h"
#include "lib1.h"
#include "Win32Dll.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0504MFC1View

IMPLEMENT_DYNCREATE(CMy0504MFC1View, CView)

BEGIN_MESSAGE_MAP(CMy0504MFC1View, CView)
END_MESSAGE_MAP()

// CMy0504MFC1View ����/����

CMy0504MFC1View::CMy0504MFC1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0504MFC1View::~CMy0504MFC1View()
{
}

BOOL CMy0504MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0504MFC1View ����

void CMy0504MFC1View::OnDraw(CDC* pDC)
{
	CMy0504MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s1,s2,s3,s4;
	s1.Format(_T("��̬���ʹ�ã�%d�Ľ׳˵���%d"), 5,factorial(5));
	pDC->TextOutW(200,100,s1);

	Fac a;
	s2.Format(_T("��̬���ʹ�ã�%.2lf�Ļ���ֵΪ%lf"),30.0,a.convert(30.0));
	pDC->TextOutW(200,150,s2);

	s3.Format(_T("��̬���ʹ�ã�%d�Ľ׳˵���%d"),6, fac(6));
	pDC->TextOutW(200, 200, s3);

	FAC b;
	s4.Format(_T("��̬���ʹ�ã�%.2lf�Ļ���ֵΪ%lf"), 60.0, b.convert(60.0));
	pDC->TextOutW(200, 250, s4);
}


// CMy0504MFC1View ���

#ifdef _DEBUG
void CMy0504MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0504MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0504MFC1Doc* CMy0504MFC1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0504MFC1Doc)));
	return (CMy0504MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0504MFC1View ��Ϣ�������

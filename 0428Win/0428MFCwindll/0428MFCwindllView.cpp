
// 0428MFCwindllView.cpp : CMy0428MFCwindllView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0428MFCwindll.h"
#endif

#include "0428MFCwindllDoc.h"
#include "0428MFCwindllView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "w32.h"
#include "Win32Dll.h"
// CMy0428MFCwindllView

IMPLEMENT_DYNCREATE(CMy0428MFCwindllView, CView)

BEGIN_MESSAGE_MAP(CMy0428MFCwindllView, CView)
END_MESSAGE_MAP()

// CMy0428MFCwindllView ����/����

CMy0428MFCwindllView::CMy0428MFCwindllView()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0428MFCwindllView::~CMy0428MFCwindllView()
{
}

BOOL CMy0428MFCwindllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0428MFCwindllView ����

void CMy0428MFCwindllView::OnDraw(CDC* pDC)
{
	CMy0428MFCwindllDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
	s= pchar();
	pDC->TextOutW(200,200,s);

	CString ss;
	ss.Format(_T("��̬�ⷵ�ص�ֵ�� %d"),GetInt());
	pDC->TextOutW(200, 230, ss);
}


// CMy0428MFCwindllView ���

#ifdef _DEBUG
void CMy0428MFCwindllView::AssertValid() const
{
	CView::AssertValid();
}

void CMy0428MFCwindllView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0428MFCwindllDoc* CMy0428MFCwindllView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0428MFCwindllDoc)));
	return (CMy0428MFCwindllDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy0428MFCwindllView ��Ϣ�������


// 0310MFC2View.cpp : CMy0310MFC2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0310MFC2.h"
#endif

#include "0310MFC2Doc.h"
#include "0310MFC2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0310MFC2View

IMPLEMENT_DYNCREATE(CMy0310MFC2View, CView)

BEGIN_MESSAGE_MAP(CMy0310MFC2View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0310MFC2View ����/����

CMy0310MFC2View::CMy0310MFC2View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0310MFC2View::~CMy0310MFC2View()
{
}

BOOL CMy0310MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0310MFC2View ����

void CMy0310MFC2View::OnDraw(CDC* /*pDC*/)
{
	CMy0310MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy0310MFC2View ���

#ifdef _DEBUG
void CMy0310MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0310MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0310MFC2Doc* CMy0310MFC2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0310MFC2Doc)));
	return (CMy0310MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0310MFC2View ��Ϣ�������


void CMy0310MFC2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy0310MFC2Doc* pDoc = GetDocument();
	CString s;
	CString C, D;
	s.Format(_T("%s+%s=%d"),"A","B", pDoc->A +pDoc->B );
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);

	CView::OnLButtonDown(nFlags, point);
}

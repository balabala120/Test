
// 0310MFC4View.cpp : CMy0310MFC4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0310MFC4.h"
#endif

#include "0310MFC4Doc.h"
#include "0310MFC4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0310MFC4View

IMPLEMENT_DYNCREATE(CMy0310MFC4View, CView)

BEGIN_MESSAGE_MAP(CMy0310MFC4View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0310MFC4View ����/����

CMy0310MFC4View::CMy0310MFC4View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0310MFC4View::~CMy0310MFC4View()
{
}

BOOL CMy0310MFC4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0310MFC4View ����

void CMy0310MFC4View::OnDraw(CDC* /*pDC*/)
{
	CMy0310MFC4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy0310MFC4View ���

#ifdef _DEBUG
void CMy0310MFC4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0310MFC4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0310MFC4Doc* CMy0310MFC4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0310MFC4Doc)));
	return (CMy0310MFC4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0310MFC4View ��Ϣ�������


void CMy0310MFC4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect cr;
	this->GetClientRect(&cr);
	CClientDC dc(this);
	if(cr.bottom -cr.top > cr.right -cr.left )
		dc.Ellipse (0,0,cr.right -cr.left , cr.right - cr.left);
	else  dc.Ellipse(0, 0, cr.bottom - cr.top, cr.bottom - cr.top);
	CView::OnLButtonDown(nFlags, point);
}

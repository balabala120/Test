
// 0327MFC3View.cpp : CMy0327MFC3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0327MFC3.h"
#endif

#include "0327MFC3Doc.h"
#include "0327MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0327MFC3View

IMPLEMENT_DYNCREATE(CMy0327MFC3View, CView)

BEGIN_MESSAGE_MAP(CMy0327MFC3View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy0327MFC3View ����/����

CMy0327MFC3View::CMy0327MFC3View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0327MFC3View::~CMy0327MFC3View()
{
}

BOOL CMy0327MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0327MFC3View ����

void CMy0327MFC3View::OnDraw(CDC* pDC)
{
	CMy0327MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	SetTimer(1,500,NULL);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	pDC->Ellipse(pDoc->cr);
}


// CMy0327MFC3View ���

#ifdef _DEBUG
void CMy0327MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0327MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0327MFC3Doc* CMy0327MFC3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0327MFC3Doc)));
	return (CMy0327MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0327MFC3View ��Ϣ�������


void CMy0327MFC3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect cc;
	GetClientRect(&cc);//ȡ�ÿͻ�����cc
	CMy0327MFC3Doc* pDoc = GetDocument();
	
	if(pDoc->cr.bottom < cc.bottom)
	{
		pDoc->cr.top += 30;
		pDoc->cr.bottom += 30;
	}
	else while (pDoc->cr.top > 0)
	{
		pDoc->cr.top -= 30;
		pDoc->cr.bottom -= 30;
	}

	Invalidate();

	CView::OnTimer(nIDEvent);
}


// 0310MFC2_1View.cpp : CMy0310MFC2_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0310MFC2_1.h"
#endif

#include "0310MFC2_1Doc.h"
#include "0310MFC2_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0310MFC2_1View

IMPLEMENT_DYNCREATE(CMy0310MFC2_1View, CView)

BEGIN_MESSAGE_MAP(CMy0310MFC2_1View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0310MFC2_1View ����/����

CMy0310MFC2_1View::CMy0310MFC2_1View()
{
	// TODO: �ڴ˴���ӹ������
	ca.SetSize(256);


}

CMy0310MFC2_1View::~CMy0310MFC2_1View()
{
}

BOOL CMy0310MFC2_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0310MFC2_1View ����

void CMy0310MFC2_1View::OnDraw(CDC* pDC)
{
	CMy0310MFC2_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca.GetAt(i));
}


// CMy0310MFC2_1View ���

#ifdef _DEBUG
void CMy0310MFC2_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0310MFC2_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0310MFC2_1Doc* CMy0310MFC2_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0310MFC2_1Doc)));
	return (CMy0310MFC2_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0310MFC2_1View ��Ϣ�������


void CMy0310MFC2_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int a = rand() % 150 + 5;
	int b = rand() % 150 + 5;
	CRect cr(point.x-a,point.y-b,point.x+a,point.y +b);
	ca.Add(cr);
	this->Invalidate();

	//CClientDC dc(this);
	//dc.Ellipse(cr );

	CView::OnLButtonDown(nFlags, point);
}

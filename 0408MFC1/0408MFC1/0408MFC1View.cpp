
// 0408MFC1View.cpp : CMy0408MFC1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0408MFC1.h"
#endif

#include "0408MFC1Doc.h"
#include "0408MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0408MFC1View

IMPLEMENT_DYNCREATE(CMy0408MFC1View, CView)

BEGIN_MESSAGE_MAP(CMy0408MFC1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy0408MFC1View ����/����

CMy0408MFC1View::CMy0408MFC1View()
{
	// TODO: �ڴ˴���ӹ������
	cr.top = 100;
	cr.left = 100;
	cr.bottom = 300;
	cr.right = 300;
	mouse = 0;
	flag = 0;
}

CMy0408MFC1View::~CMy0408MFC1View()
{
}

BOOL CMy0408MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0408MFC1View ����

void CMy0408MFC1View::OnDraw(CDC* pDC)
{
	CMy0408MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy0408MFC1View ���

#ifdef _DEBUG
void CMy0408MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0408MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0408MFC1Doc* CMy0408MFC1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0408MFC1Doc)));
	return (CMy0408MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0408MFC1View ��Ϣ�������


void CMy0408MFC1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if ((cr.left <= point.x)&& (point.x <= cr.right) && (cr.top <= point.y)&&(point.y <= cr.bottom))
		//�ж��������Ƿ��ھ����ڰ���
	{
		flag = 1;
		mouse = point;
	}
	
	CView::OnLButtonDown(nFlags, point);
}


void CMy0408MFC1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 1)//ֻ������������ʱ���ػ�
	{
		cr.top += point.y - mouse.y;
		cr.bottom += point.y - mouse.y;
		cr.left += point.x - mouse.x;
		cr.right += point.x - mouse.x;
		mouse = point;
		Invalidate();
	}
	
	CView::OnMouseMove(nFlags, point);
}


void CMy0408MFC1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 0;
	CView::OnLButtonUp(nFlags, point);
}

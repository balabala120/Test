
// 0408MFC3View.cpp : CMy0408MFC3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0408MFC3.h"
#endif

#include "0408MFC3Doc.h"
#include "0408MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0408MFC3View

IMPLEMENT_DYNCREATE(CMy0408MFC3View, CView)

BEGIN_MESSAGE_MAP(CMy0408MFC3View, CView)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMy0408MFC3View ����/����

CMy0408MFC3View::CMy0408MFC3View()
{
	// TODO: �ڴ˴���ӹ������
	cr.top = 100;
	cr.left = 100;
	cr.bottom = 200;
	cr.right = 200;
	flag = 0;
	rl = 0;
}

CMy0408MFC3View::~CMy0408MFC3View()
{
}

BOOL CMy0408MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0408MFC3View ����

void CMy0408MFC3View::OnDraw(CDC* pDC)
{
	CMy0408MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	SetTimer(1, 500, NULL);
	pDC->Ellipse(cr);
	
}


// CMy0408MFC3View ���

#ifdef _DEBUG
void CMy0408MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0408MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0408MFC3Doc* CMy0408MFC3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0408MFC3Doc)));
	return (CMy0408MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0408MFC3View ��Ϣ�������


void CMy0408MFC3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 1)
	{
		CRect cc;
		GetClientRect(&cc);//ȡ�ÿͻ�����cc
		if (cr.right >= cc.right) rl = 1;//С�����ұ���ı䷽��   �����ƶ�
		if (cr.left <= cc.left) rl = 0;//С���������ı䷽��   �����ƶ�
		if (rl==0)//�����ƶ�
		{
			cr.left += 30;
			cr.right += 30;
		}
		if (rl==1)//�����ƶ�
		{
			cr.left-= 30;
			cr.right -= 30;
		}
		Invalidate();
	}
	CView::OnTimer(nIDEvent);
}


void CMy0408MFC3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMy0408MFC3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 0;
	CView::OnLButtonDblClk(nFlags, point);
}

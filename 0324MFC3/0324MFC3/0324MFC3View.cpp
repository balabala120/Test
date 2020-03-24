
// 0324MFC3View.cpp : CMy0324MFC3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0324MFC3.h"
#endif

#include "0324MFC3Doc.h"
#include "0324MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0324MFC3View

IMPLEMENT_DYNCREATE(CMy0324MFC3View, CView)

BEGIN_MESSAGE_MAP(CMy0324MFC3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDM_LINE, &CMy0324MFC3View::OnLine)
	ON_COMMAND(IDM_RECTANGLE, &CMy0324MFC3View::OnRectangle)
	ON_COMMAND(IDM_ELLIPSE, &CMy0324MFC3View::OnEllipse)
END_MESSAGE_MAP()

// CMy0324MFC3View ����/����

CMy0324MFC3View::CMy0324MFC3View()
{
	// TODO: �ڴ˴���ӹ������
	flag = 0;
	cr.top = 0; cr.left = 0;
	cr.bottom = 0; cr.right = 0;

}

CMy0324MFC3View::~CMy0324MFC3View()
{
}

BOOL CMy0324MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0324MFC3View ����

void CMy0324MFC3View::OnDraw(CDC* pDC)
{
	CMy0324MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (flag==1)
	{
		pDC->MoveTo(point1);
		pDC->LineTo(point2);
	}
	if (flag == 2)
	{
		pDC->Rectangle(point1.x,point1.y,point2.x,point2.y );
	}
	if (flag == 3)
	{
		pDC->Ellipse(point1.x,point1.y,point2.x,point2.y);
	}
}


// CMy0324MFC3View ��ӡ

BOOL CMy0324MFC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0324MFC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0324MFC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0324MFC3View ���

#ifdef _DEBUG
void CMy0324MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0324MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0324MFC3Doc* CMy0324MFC3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0324MFC3Doc)));
	return (CMy0324MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0324MFC3View ��Ϣ�������


void CMy0324MFC3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	point1 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMy0324MFC3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	point2 = point;
	Invalidate(FALSE);
	CView::OnLButtonUp(nFlags, point);
}


void CMy0324MFC3View::OnLine()
{
	// TODO: �ڴ���������������
	flag = 1;
	
}


void CMy0324MFC3View::OnRectangle()
{
	// TODO: �ڴ���������������
	flag = 2;
	
}


void CMy0324MFC3View::OnEllipse()
{
	// TODO: �ڴ���������������
	flag = 3;
	

}

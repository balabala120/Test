
// 0310MFC3View.cpp : CMy0310MFC3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0310MFC3.h"
#endif

#include "0310MFC3Doc.h"
#include "0310MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0310MFC3View

IMPLEMENT_DYNCREATE(CMy0310MFC3View, CView)

BEGIN_MESSAGE_MAP(CMy0310MFC3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0310MFC3View ����/����

CMy0310MFC3View::CMy0310MFC3View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0310MFC3View::~CMy0310MFC3View()
{
}

BOOL CMy0310MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0310MFC3View ����

void CMy0310MFC3View::OnDraw(CDC* pDC)
{
	CMy0310MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);

}


// CMy0310MFC3View ��ӡ

BOOL CMy0310MFC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0310MFC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0310MFC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0310MFC3View ���

#ifdef _DEBUG
void CMy0310MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0310MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0310MFC3Doc* CMy0310MFC3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0310MFC3Doc)));
	return (CMy0310MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0310MFC3View ��Ϣ�������


void CMy0310MFC3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy0310MFC3Doc* pDoc = GetDocument();
	CString s;
	CClientDC dc(this);
	
	if (pDoc->A.PtInRect(point))
	{
		pDoc->a = rand() % 150 + 5;
		s.Format(_T("a=%d"), pDoc->a);
		dc.TextOutW(point.x, point.y, s);
	}
	else
	{
		if (pDoc->B.PtInRect(point))
		{
			pDoc->b = rand() % 150 + 5;
			s.Format(_T("b=%d"), pDoc->b);
			dc.TextOutW(point.x, point.y, s);
		}//if
		else
		{
			s.Format(_T("�����Ч"));
			dc.TextOutW(point.x, point.y, s);
		}//else
	}//else
	CView::OnLButtonDown(nFlags, point);
}


void CMy0310MFC3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy0310MFC3Doc* pDoc = GetDocument();
	CString s;
	CClientDC dc(this);
	if (pDoc->C.PtInRect(point))
	{
		s.Format(_T("a+b=%d"), pDoc->a+pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	else
	{
		s.Format(_T("�����Ч"));
		dc.TextOutW(point.x, point.y, s);
	}

	CView::OnRButtonDown(nFlags, point);
}

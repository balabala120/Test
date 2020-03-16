
// 0316MFCView.cpp : CMy0316MFCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0316MFC.h"
#endif

#include "0316MFCDoc.h"
#include "0316MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0316MFCView

IMPLEMENT_DYNCREATE(CMy0316MFCView, CView)

BEGIN_MESSAGE_MAP(CMy0316MFCView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy0316MFCView ����/����

CMy0316MFCView::CMy0316MFCView()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0316MFCView::~CMy0316MFCView()
{
}

BOOL CMy0316MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0316MFCView ����

void CMy0316MFCView::OnDraw(CDC* pDC)
{
	CMy0316MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->cr );
}


// CMy0316MFCView ��ӡ

BOOL CMy0316MFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0316MFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0316MFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0316MFCView ���

#ifdef _DEBUG
void CMy0316MFCView::AssertValid() const
{
	CView::AssertValid();
}

void CMy0316MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0316MFCDoc* CMy0316MFCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0316MFCDoc)));
	return (CMy0316MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy0316MFCView ��Ϣ�������


void CMy0316MFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy0316MFCDoc* pDoc = GetDocument();
	pDoc->cr.left = point.x;
	pDoc->cr.top = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void CMy0316MFCView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy0316MFCDoc* pDoc = GetDocument();
	pDoc->cr.right  = point.x;
	pDoc->cr.bottom = point.y;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonUp(nFlags, point);
}


void CMy0316MFCView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s;
	s.Format(_T("x=%d,y=%d"),point.x,point.y);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnMouseMove(nFlags, point);
}

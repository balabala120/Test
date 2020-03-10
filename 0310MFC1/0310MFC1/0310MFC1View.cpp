
// 0310MFC1View.cpp : CMy0310MFC1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0310MFC1.h"
#endif

#include "0310MFC1Doc.h"
#include "0310MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0310MFC1View

IMPLEMENT_DYNCREATE(CMy0310MFC1View, CView)

BEGIN_MESSAGE_MAP(CMy0310MFC1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy0310MFC1View ����/����

CMy0310MFC1View::CMy0310MFC1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0310MFC1View::~CMy0310MFC1View()
{
}

BOOL CMy0310MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0310MFC1View ����

void CMy0310MFC1View::OnDraw(CDC* /*pDC*/)
{
	CMy0310MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy0310MFC1View ��ӡ

BOOL CMy0310MFC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0310MFC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0310MFC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0310MFC1View ���

#ifdef _DEBUG
void CMy0310MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0310MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0310MFC1Doc* CMy0310MFC1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0310MFC1Doc)));
	return (CMy0310MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0310MFC1View ��Ϣ�������


void CMy0310MFC1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy0310MFC1Doc* pDoc = GetDocument();
	CString s1;
	s1.Format(pDoc->Ldown);
	
	CClientDC dc(this);
	dc.TextOutW(point.x, point.y, s1);

	CView::OnLButtonDown(nFlags, point);
}


void CMy0310MFC1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy0310MFC1Doc* pDoc = GetDocument();
	CString s2;
	s2.Format(pDoc->Lup);

	CClientDC dc(this);
	dc.TextOutW(point.x, point.y, s2);

	CView::OnLButtonUp(nFlags, point);
}


// 0331MFC1View.cpp : CMy0331MFC1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0331MFC1.h"
#endif

#include "0331MFC1Doc.h"
#include "0331MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0331MFC1View

IMPLEMENT_DYNCREATE(CMy0331MFC1View, CView)

BEGIN_MESSAGE_MAP(CMy0331MFC1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0331MFC1View ����/����

CMy0331MFC1View::CMy0331MFC1View()
{
	// TODO: �ڴ˴���ӹ������
	s = "";
	insert = 0;
}

CMy0331MFC1View::~CMy0331MFC1View()
{
}

BOOL CMy0331MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0331MFC1View ����

void CMy0331MFC1View::OnDraw(CDC* pDC)
{
	CMy0331MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(20, 30, 1000, 400);



}


// CMy0331MFC1View ��ӡ

BOOL CMy0331MFC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0331MFC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0331MFC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0331MFC1View ���

#ifdef _DEBUG
void CMy0331MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0331MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0331MFC1Doc* CMy0331MFC1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0331MFC1Doc)));
	return (CMy0331MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0331MFC1View ��Ϣ�������


void CMy0331MFC1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	s += (char)nChar;
	dc.TextOutW(30, 40, s);
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMy0331MFC1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	insert = point;//��ȡ����λ��
	CView::OnLButtonDown(nFlags, point);
}


// 0310MFC2_2View.cpp : CMy0310MFC2_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0310MFC2_2.h"
#endif

#include "0310MFC2_2Doc.h"
#include "0310MFC2_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0310MFC2_2View

IMPLEMENT_DYNCREATE(CMy0310MFC2_2View, CView)

BEGIN_MESSAGE_MAP(CMy0310MFC2_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0310MFC2_2View ����/����

CMy0310MFC2_2View::CMy0310MFC2_2View()
{
	// TODO: �ڴ˴���ӹ������
	

}

CMy0310MFC2_2View::~CMy0310MFC2_2View()
{
}

BOOL CMy0310MFC2_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0310MFC2_2View ����

void CMy0310MFC2_2View::OnDraw(CDC* pDC)
{
	CMy0310MFC2_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	for (int i = 0; i < pDoc->ca.GetSize(); i++)
		pDC->Ellipse(pDoc->ca.GetAt(i));
}


// CMy0310MFC2_2View ��ӡ

BOOL CMy0310MFC2_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0310MFC2_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0310MFC2_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0310MFC2_2View ���

#ifdef _DEBUG
void CMy0310MFC2_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0310MFC2_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0310MFC2_2Doc* CMy0310MFC2_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0310MFC2_2Doc)));
	return (CMy0310MFC2_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0310MFC2_2View ��Ϣ�������


void CMy0310MFC2_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int a = rand() % 150 + 5;
	int b = rand() % 150 + 5;
	CRect cr(point.x - a, point.y - b, point.x + a, point.y + b);
	CMy0310MFC2_2Doc* pDoc = GetDocument();
	pDoc->ca.Add(cr);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

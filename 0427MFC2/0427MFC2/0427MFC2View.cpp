
// 0427MFC2View.cpp : CMy0427MFC2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0427MFC2.h"
#endif

#include "0427MFC2Doc.h"
#include "0427MFC2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0427MFC2View

IMPLEMENT_DYNCREATE(CMy0427MFC2View, CView)

BEGIN_MESSAGE_MAP(CMy0427MFC2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy0427MFC2View ����/����

CMy0427MFC2View::CMy0427MFC2View()
{
	// TODO: �ڴ˴���ӹ������
	flag_mouse = 0;
	mouse = NULL;
}

CMy0427MFC2View::~CMy0427MFC2View()
{
}

BOOL CMy0427MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0427MFC2View ����

void CMy0427MFC2View::OnDraw(CDC* pDC)
{
	CMy0427MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	int n = pDoc->ca.GetCount();
	for (int i = 0; i < n; i++)
	{
		pDC->Ellipse(pDoc->ca[i]);
	}
	pDC->Ellipse(cr);

}


// CMy0427MFC2View ��ӡ

BOOL CMy0427MFC2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0427MFC2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0427MFC2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0427MFC2View ���

#ifdef _DEBUG
void CMy0427MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0427MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0427MFC2Doc* CMy0427MFC2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0427MFC2Doc)));
	return (CMy0427MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0427MFC2View ��Ϣ�������


void CMy0427MFC2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag_mouse = 1;
	mouse = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMy0427MFC2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag_mouse == 1)
	{
		cr.left = mouse.x;        //���������ʹ���϶��Ż�������Բ
		cr.top = mouse.y;
		cr.right = point.x;
		cr.bottom = point.y;
		InvalidateRect(&cr);          //ˢ��ָ������
	}
	
	CView::OnMouseMove(nFlags, point);
}


void CMy0427MFC2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy0427MFC2Doc* pDoc = GetDocument();
	flag_mouse = 0;
	pDoc->ca.Add(cr);
	CView::OnLButtonUp(nFlags, point);
}

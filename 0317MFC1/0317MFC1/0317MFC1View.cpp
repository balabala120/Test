
// 0317MFC1View.cpp : CMy0317MFC1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0317MFC1.h"
#endif

#include "0317MFC1Doc.h"
#include "0317MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0317MFC1View

IMPLEMENT_DYNCREATE(CMy0317MFC1View, CView)

BEGIN_MESSAGE_MAP(CMy0317MFC1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy0317MFC1View ����/����

CMy0317MFC1View::CMy0317MFC1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0317MFC1View::~CMy0317MFC1View()
{
}

BOOL CMy0317MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0317MFC1View ����

void CMy0317MFC1View::OnDraw(CDC* /*pDC*/)
{
	CMy0317MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
	CClientDC dc(this);
	s.Format(_T("MouseMove������%d��,�����ƶ�%d�����ط���һ��"), pDoc->i,pDoc->n);
	dc.TextOutW(200, 200, s);
}


// CMy0317MFC1View ��ӡ

BOOL CMy0317MFC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0317MFC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0317MFC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0317MFC1View ���

#ifdef _DEBUG
void CMy0317MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0317MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0317MFC1Doc* CMy0317MFC1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0317MFC1Doc)));
	return (CMy0317MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0317MFC1View ��Ϣ�������


void CMy0317MFC1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy0317MFC1Doc* pDoc = GetDocument();
	pDoc->op = point;
	
	CView::OnLButtonDown(nFlags, point);
}


void CMy0317MFC1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy0317MFC1Doc* pDoc = GetDocument();
	
	if(nFlags&MK_LBUTTON)
	{
		pDoc->i++;
		pDoc->n = point.x - pDoc->op.x;
		pDoc->op = point;
		InvalidateRect(NULL, FALSE); 
	}
	

	CView::OnMouseMove(nFlags, point);
}

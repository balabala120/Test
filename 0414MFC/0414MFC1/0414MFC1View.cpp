
// 0414MFC1View.cpp : CMy0414MFC1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0414MFC1.h"
#endif

#include "0414MFC1Doc.h"
#include "0414MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0414MFC1View

IMPLEMENT_DYNCREATE(CMy0414MFC1View, CView)

BEGIN_MESSAGE_MAP(CMy0414MFC1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMy0414MFC1View ����/����

CMy0414MFC1View::CMy0414MFC1View()
{
	// TODO: �ڴ˴���ӹ������
	filename = "";
}

CMy0414MFC1View::~CMy0414MFC1View()
{
}

BOOL CMy0414MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0414MFC1View ����

void CMy0414MFC1View::OnDraw(CDC* pDC)
{
	CMy0414MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s("(1)˫��������, �������ļ��Ի��򣬴���ѡ����һ���ļ����� �ڿͻ�����ʾ���ļ���;");
	pDC->TextOutW(10,10,s);
}


// CMy0414MFC1View ��ӡ

BOOL CMy0414MFC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0414MFC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0414MFC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0414MFC1View ���

#ifdef _DEBUG
void CMy0414MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0414MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0414MFC1Doc* CMy0414MFC1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0414MFC1Doc)));
	return (CMy0414MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0414MFC1View ��Ϣ�������


void CMy0414MFC1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		filename = cfd.GetFileName();
		dc.TextOutW(200, 200, filename);
	}
	CView::OnLButtonDblClk(nFlags, point);
}

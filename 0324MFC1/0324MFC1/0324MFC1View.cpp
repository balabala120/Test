
// 0324MFC1View.cpp : CMy0324MFC1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0324MFC1.h"
#endif

#include "0324MFC1Doc.h"
#include "0324MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0324MFC1View

IMPLEMENT_DYNCREATE(CMy0324MFC1View, CView)

BEGIN_MESSAGE_MAP(CMy0324MFC1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOWNAME, &CMy0324MFC1View::OnShowname)
END_MESSAGE_MAP()

// CMy0324MFC1View ����/����

CMy0324MFC1View::CMy0324MFC1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0324MFC1View::~CMy0324MFC1View()
{
}

BOOL CMy0324MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0324MFC1View ����

void CMy0324MFC1View::OnDraw(CDC* /*pDC*/)
{
	CMy0324MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
	s.Format(_T("��ʾ�����������123����ʾ����"));
	CClientDC dc(this);
	dc.TextOutW(50, 50, s);

}


// CMy0324MFC1View ��ӡ

BOOL CMy0324MFC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0324MFC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0324MFC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0324MFC1View ���

#ifdef _DEBUG
void CMy0324MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0324MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0324MFC1Doc* CMy0324MFC1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0324MFC1Doc)));
	return (CMy0324MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0324MFC1View ��Ϣ�������


void CMy0324MFC1View::OnShowname()
{
	// TODO: �ڴ���������������
	CString s;
	s.Format(_T("����÷"));
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);

}

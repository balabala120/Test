
// 0407MFC1View.cpp : CMy0407MFC1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0407MFC1.h"
#endif

#include "0407MFC1Doc.h"
#include "0407MFC1View.h"
#include "MyDlg1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0407MFC1View

IMPLEMENT_DYNCREATE(CMy0407MFC1View, CView)

BEGIN_MESSAGE_MAP(CMy0407MFC1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popout, &CMy0407MFC1View::Onpopout)
END_MESSAGE_MAP()

// CMy0407MFC1View ����/����

CMy0407MFC1View::CMy0407MFC1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0407MFC1View::~CMy0407MFC1View()
{
}

BOOL CMy0407MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0407MFC1View ����

void CMy0407MFC1View::OnDraw(CDC* /*pDC*/)
{
	CMy0407MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy0407MFC1View ��ӡ

BOOL CMy0407MFC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0407MFC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0407MFC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0407MFC1View ���

#ifdef _DEBUG
void CMy0407MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0407MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0407MFC1Doc* CMy0407MFC1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0407MFC1Doc)));
	return (CMy0407MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0407MFC1View ��Ϣ�������


void CMy0407MFC1View::Onpopout()
{
	// TODO: �ڴ���������������
	MyDlg1 dlg;
	int r = dlg.DoModal();
	if (r == IDOK) 
	{
		CString s ("�����˳��Ի���");
		CClientDC dc(this);
		dc.TextOutW(200, 200,s );
	}
}

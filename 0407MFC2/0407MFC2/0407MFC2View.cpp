
// 0407MFC2View.cpp : CMy0407MFC2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0407MFC2.h"
#endif

#include "0407MFC2Doc.h"
#include "0407MFC2View.h"
#include "MyDlg1.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0407MFC2View

IMPLEMENT_DYNCREATE(CMy0407MFC2View, CView)

BEGIN_MESSAGE_MAP(CMy0407MFC2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_pop, &CMy0407MFC2View::Onpop)

END_MESSAGE_MAP()

// CMy0407MFC2View ����/����

CMy0407MFC2View::CMy0407MFC2View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0407MFC2View::~CMy0407MFC2View()
{
}

BOOL CMy0407MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0407MFC2View ����

void CMy0407MFC2View::OnDraw(CDC* /*pDC*/)
{
	CMy0407MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy0407MFC2View ��ӡ

BOOL CMy0407MFC2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0407MFC2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0407MFC2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0407MFC2View ���

#ifdef _DEBUG
void CMy0407MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0407MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0407MFC2Doc* CMy0407MFC2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0407MFC2Doc)));
	return (CMy0407MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0407MFC2View ��Ϣ�������


void CMy0407MFC2View::Onpop()
{
	// TODO: �ڴ���������������
	MyDlg1 *dlg=new MyDlg1;
	dlg->Create(IDD_DIALOG1);
	dlg->ShowWindow(1);

}



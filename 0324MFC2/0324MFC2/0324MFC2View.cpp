
// 0324MFC2View.cpp : CMy0324MFC2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0324MFC2.h"
#endif

#include "0324MFC2Doc.h"
#include "0324MFC2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0324MFC2View

IMPLEMENT_DYNCREATE(CMy0324MFC2View, CView)

BEGIN_MESSAGE_MAP(CMy0324MFC2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy0324MFC2View ����/����

CMy0324MFC2View::CMy0324MFC2View()
{
	// TODO: �ڴ˴���ӹ������
	BITMAP BM;//��ʼ��
	bitmap1_car.LoadBitmap(IDCANCEL);
	bitmap1_car.GetBitmap(&BM);
		bitmap1_width = BM.bmWidth;
	bitmap1_height =BM.bmHeight;

	
}

CMy0324MFC2View::~CMy0324MFC2View()
{
}

BOOL CMy0324MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0324MFC2View ����

void CMy0324MFC2View::OnDraw(CDC* pDC)
{
	CMy0324MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CDC MemDC;//��ͼ
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(bitmap1_car);
	pDC->BitBlt(0, 0, bitmap1_width, bitmap1_height, &MemDC, 0, 0,SRCCOPY);

}


// CMy0324MFC2View ��ӡ

BOOL CMy0324MFC2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0324MFC2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0324MFC2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0324MFC2View ���

#ifdef _DEBUG
void CMy0324MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0324MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0324MFC2Doc* CMy0324MFC2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0324MFC2Doc)));
	return (CMy0324MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0324MFC2View ��Ϣ�������

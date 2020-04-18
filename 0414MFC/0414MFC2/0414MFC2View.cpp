
// 0414MFC2View.cpp : CMy0414MFC2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0414MFC2.h"
#endif

#include "0414MFC2Doc.h"
#include "0414MFC2View.h"
#include "Mydlg1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0414MFC2View

IMPLEMENT_DYNCREATE(CMy0414MFC2View, CView)

BEGIN_MESSAGE_MAP(CMy0414MFC2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_ShowFname, &CMy0414MFC2View::OnShowfname)
END_MESSAGE_MAP()

// CMy0414MFC2View ����/����

CMy0414MFC2View::CMy0414MFC2View()
{
	// TODO: �ڴ˴���ӹ������
	filename = "";
}

CMy0414MFC2View::~CMy0414MFC2View()
{
}

BOOL CMy0414MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0414MFC2View ����

void CMy0414MFC2View::OnDraw(CDC* pDC)
{
	CMy0414MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s1("(1)˫��������, �������ļ��Ի��򣬴���ѡ����һ���ļ����� �ڿͻ�����ʾ���ļ���;");
	CString s2("(2)Ȼ��������ͼ-��ʾ��ѡȡ�ļ������� ����һ���Ի���ʹ���ļ����ڶԻ����е�һ���༭�ؼ�����ʾ������");
	pDC->TextOutW(10, 10, s1);
	pDC->TextOutW(10, 40, s2);
}


// CMy0414MFC2View ��ӡ

BOOL CMy0414MFC2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0414MFC2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0414MFC2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0414MFC2View ���

#ifdef _DEBUG
void CMy0414MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0414MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0414MFC2Doc* CMy0414MFC2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0414MFC2Doc)));
	return (CMy0414MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0414MFC2View ��Ϣ�������


void CMy0414MFC2View::OnLButtonDblClk(UINT nFlags, CPoint point)
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


void CMy0414MFC2View::OnShowfname()
{
	// TODO: �ڴ���������������
	Mydlg1 dlg;
	dlg.fname = filename;
	UpdateData(false);
	dlg.DoModal();//�ȸ�����������ʾ�Ի���
}

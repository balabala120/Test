
// 0414MFC3View.cpp : CMy0414MFC3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0414MFC3.h"
#endif

#include "0414MFC3Doc.h"
#include "0414MFC3View.h"
#include "MyDlg2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0414MFC3View

IMPLEMENT_DYNCREATE(CMy0414MFC3View, CView)

BEGIN_MESSAGE_MAP(CMy0414MFC3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ShowFileName, &CMy0414MFC3View::OnShowfilename)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMy0414MFC3View ����/����

CMy0414MFC3View::CMy0414MFC3View()
{
	// TODO: �ڴ˴���ӹ������
	fname = "";
	
}

CMy0414MFC3View::~CMy0414MFC3View()
{
}

BOOL CMy0414MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0414MFC3View ����

void CMy0414MFC3View::OnDraw(CDC* pDC)
{
	CMy0414MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s1("(1)˫��������, �������ļ��Ի��򣬴���ѡ����һ���ļ����� �ڿͻ�����ʾ���ļ���;");
	CString s2("(2)Ȼ��������ͼ-��ʾ��ѡȡ�ļ������� ����һ���Ի���ʹ���ļ����ڶԻ����е�һ���༭�ؼ�����ʾ������");
	CString s3("(3)���ļ����ڶԻ����е�һ���б������ʾ����");
	pDC->TextOutW(10, 10, s1);
	pDC->TextOutW(10, 40, s2);
	pDC->TextOutW(10, 70, s3);
}


// CMy0414MFC3View ��ӡ

BOOL CMy0414MFC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0414MFC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0414MFC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0414MFC3View ���

#ifdef _DEBUG
void CMy0414MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0414MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0414MFC3Doc* CMy0414MFC3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0414MFC3Doc)));
	return (CMy0414MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0414MFC3View ��Ϣ�������


void CMy0414MFC3View::OnShowfilename()
{
	// TODO: �ڴ���������������
	MyDlg2 *dlg = new MyDlg2();       //��ģʽ�Ի�����һ���б��LBox��һ���༭�ؼ�filename
	dlg->filename = fname;            //fname���ļ�����ȫ�ֱ����ַ�����
	UpdateData(false);                //�ȸ��������ٴ�������
	dlg->Create(IDD_DIALOG1);
	dlg->LBox.InsertString(-1,fname);  //�������Ҫ�ڴ�������֮��
	dlg->ShowWindow(1);
}


void CMy0414MFC3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		fname = cfd.GetFileName();
		dc.TextOutW(200, 200, fname);
	}
	CView::OnLButtonDblClk(nFlags, point);
}

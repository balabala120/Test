
// 0330MFC2View.cpp : CMy0330MFC2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0330MFC2.h"
#endif

#include "0330MFC2Doc.h"
#include "0330MFC2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0330MFC2View

IMPLEMENT_DYNCREATE(CMy0330MFC2View, CView)

BEGIN_MESSAGE_MAP(CMy0330MFC2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMy0330MFC2View::OnFileOpen)
END_MESSAGE_MAP()

// CMy0330MFC2View ����/����

CMy0330MFC2View::CMy0330MFC2View()
{
	// TODO: �ڴ˴���ӹ������
	flag = 0;
}

CMy0330MFC2View::~CMy0330MFC2View()
{
}

BOOL CMy0330MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0330MFC2View ����

void CMy0330MFC2View::OnDraw(CDC* pDC)
{
	CMy0330MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect cc;
	GetClientRect(&cc);    //ȡ�ÿͻ�����cc
	if(flag==1)
	{ 
		
		pDC->TextOutW(0, 0, pDoc->filename);
		pDoc->img.Draw(pDC->m_hDC, cc.CenterPoint().x - pDoc->img.GetWidth()/ 2, cc.CenterPoint().y - pDoc->img.GetHeight() / 2, pDoc->img.GetWidth(), pDoc->img.GetHeight());
		
	}
	
}


// CMy0330MFC2View ��ӡ

BOOL CMy0330MFC2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0330MFC2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0330MFC2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0330MFC2View ���

#ifdef _DEBUG
void CMy0330MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0330MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0330MFC2Doc* CMy0330MFC2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0330MFC2Doc)));
	return (CMy0330MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0330MFC2View ��Ϣ�������


void CMy0330MFC2View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CMy0330MFC2Doc* pDoc = GetDocument();
	CFileDialog cfd(true);  //��������
	int r = cfd.DoModal();  //�����Ի���
	if (r == IDOK)        //����˳��Ի���ʱѡ��ΪOK�Ļ�
	{
		pDoc->filename = cfd.GetPathName();
		pDoc->img.Load(pDoc->filename);
		flag = 1;
		Invalidate();
	}
}

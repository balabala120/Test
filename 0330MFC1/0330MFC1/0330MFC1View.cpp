
// 0330MFC1View.cpp : CMy0330MFC1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0330MFC1.h"
#endif

#include "0330MFC1Doc.h"
#include "0330MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0330MFC1View

IMPLEMENT_DYNCREATE(CMy0330MFC1View, CView)

BEGIN_MESSAGE_MAP(CMy0330MFC1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMy0330MFC1View::OnFileOpen)
END_MESSAGE_MAP()

// CMy0330MFC1View ����/����

CMy0330MFC1View::CMy0330MFC1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0330MFC1View::~CMy0330MFC1View()
{
}

BOOL CMy0330MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0330MFC1View ����

void CMy0330MFC1View::OnDraw(CDC* pDC)
{
	CMy0330MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy0330MFC1View ��ӡ

BOOL CMy0330MFC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0330MFC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0330MFC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0330MFC1View ���

#ifdef _DEBUG
void CMy0330MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0330MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0330MFC1Doc* CMy0330MFC1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0330MFC1Doc)));
	return (CMy0330MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0330MFC1View ��Ϣ�������


void CMy0330MFC1View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CRect cc;
	GetClientRect(&cc);    //ȡ�ÿͻ�����cc
	CFileDialog cfd(true);  //��������
	int r = cfd.DoModal();  //�����Ի���
	CClientDC dc(this);
	if (r == IDOK)        //����˳��Ի���ʱѡ��ΪOK�Ļ�
	{
		CString filename = cfd.GetPathName();
		dc.TextOutW(0, 0, filename);
		CImage img;
		img.Load(filename);
		img.Draw(GetDC()->m_hDC, cc.CenterPoint().x-img.GetWidth()/2, cc.CenterPoint().y - img.GetHeight()/2, img.GetWidth(), img.GetHeight());

	}
}

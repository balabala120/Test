
// 0323MFC1_1View.cpp : CMy0323MFC1_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0323MFC1_1.h"
#endif

#include "0323MFC1_1Doc.h"
#include "0323MFC1_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0323MFC1_1View

IMPLEMENT_DYNCREATE(CMy0323MFC1_1View, CView)

BEGIN_MESSAGE_MAP(CMy0323MFC1_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOWCIRCLES, &CMy0323MFC1_1View::OnShowcircles)
END_MESSAGE_MAP()

// CMy0323MFC1_1View ����/����

CMy0323MFC1_1View::CMy0323MFC1_1View()
{
	// TODO: �ڴ˴���ӹ������
	cs.SetSize(200);
	
	
}

CMy0323MFC1_1View::~CMy0323MFC1_1View()
{
}

BOOL CMy0323MFC1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0323MFC1_1View ����

void CMy0323MFC1_1View::OnDraw(CDC* pDC)
{
	CMy0323MFC1_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = cs.GetSize()-1; i >= 0; i--)
		pDC->Ellipse(cs.GetAt(i));

	
	
}


// CMy0323MFC1_1View ��ӡ

BOOL CMy0323MFC1_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0323MFC1_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0323MFC1_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0323MFC1_1View ���

#ifdef _DEBUG
void CMy0323MFC1_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0323MFC1_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0323MFC1_1Doc* CMy0323MFC1_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0323MFC1_1Doc)));
	return (CMy0323MFC1_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0323MFC1_1View ��Ϣ�������


void CMy0323MFC1_1View::OnShowcircles()
{
	// TODO: �ڴ���������������
	CRect cr;
	this->GetClientRect(&cr);//ȡ�ÿͻ���
	center = cr.CenterPoint();//���岢��ʼ���ͻ�������
	for (int i = 0; i < 10; i++)
	{
		CRect c1;
		c1.top = center.y -(i+1)* 20; c1.left = center.x - (i + 1) * 20;
		c1.bottom = center.y + (i + 1) * 20; c1.right = center.x + (i + 1) * 20;
		cs.SetAt(i,c1);
	}
	Invalidate();
	
	//CRect c1(center.y - 50, center.x - 50, center.y + 50, center.x + 50);
	//CRect c2(center.y - 100,center.x - 100,center.y + 100,center.x + 100);
	//cs.SetAt(1,c2);
	
}

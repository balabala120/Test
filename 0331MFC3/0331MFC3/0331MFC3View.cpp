
// 0331MFC3View.cpp : CMy0331MFC3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0331MFC3.h"
#endif

#include "0331MFC3Doc.h"
#include "0331MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0331MFC3View

IMPLEMENT_DYNCREATE(CMy0331MFC3View, CView)

BEGIN_MESSAGE_MAP(CMy0331MFC3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMy0331MFC3View ����/����

CMy0331MFC3View::CMy0331MFC3View()
{
	// TODO: �ڴ˴���ӹ������
	cr.top = 100;cr.left=100;
	cr.bottom = 500; cr.right = 500;
}

CMy0331MFC3View::~CMy0331MFC3View()
{
}

BOOL CMy0331MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0331MFC3View ����

void CMy0331MFC3View::OnDraw(CDC* pDC)
{
	CMy0331MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(cr);
}


// CMy0331MFC3View ��ӡ

BOOL CMy0331MFC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0331MFC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0331MFC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0331MFC3View ���

#ifdef _DEBUG
void CMy0331MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0331MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0331MFC3Doc* CMy0331MFC3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0331MFC3Doc)));
	return (CMy0331MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0331MFC3View ��Ϣ�������

int i=0;//���ڱ�־�ڼ���
void CMy0331MFC3View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	s += (char)nChar;
	CSize sz = dc.GetTextExtent(s);
	if (cr.left + 5 + sz.cx >= cr.right - 10)//�ж��Ƿ񼴽�������cr��Ե�����������
	{
		i++;//i������־�ڼ��� 
			//dc.TextOutW(500, 500, _T("��������"));
		s.Empty();
		s += (char)nChar;
		sz = dc.GetTextExtent(s);
	}
	dc.TextOutW(cr.left+5,cr.top+i*sz.cy+5,s);

	CView::OnChar(nChar, nRepCnt, nFlags);
}

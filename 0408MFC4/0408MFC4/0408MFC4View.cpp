
// 0408MFC4View.cpp : CMy0408MFC4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0408MFC4.h"
#endif

#include "0408MFC4Doc.h"
#include "0408MFC4View.h"
#include "MyDlg1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0408MFC4View

IMPLEMENT_DYNCREATE(CMy0408MFC4View, CView)

BEGIN_MESSAGE_MAP(CMy0408MFC4View, CView)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMy0408MFC4View ����/����

CMy0408MFC4View::CMy0408MFC4View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0408MFC4View::~CMy0408MFC4View()
{
}

BOOL CMy0408MFC4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0408MFC4View ����

void CMy0408MFC4View::OnDraw(CDC* /*pDC*/)
{
	CMy0408MFC4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s ("�ͻ���˫�������Ի���");
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);

}


// CMy0408MFC4View ���

#ifdef _DEBUG
void CMy0408MFC4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0408MFC4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0408MFC4Doc* CMy0408MFC4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0408MFC4Doc)));
	return (CMy0408MFC4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0408MFC4View ��Ϣ�������


void CMy0408MFC4View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	MyDlg1 *pD = new MyDlg1;
	pD->s1 = "";//�������༭�ؼ���Ӧ�ı�����ʼ��
	pD->a = 0;
	pD->s2 = "";
	pD->Create(IDD_DIALOG1);
	pD->ShowWindow(1); 

	CView::OnLButtonDblClk(nFlags, point);
}


// 0408MFC2View.cpp : CMy0408MFC2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0408MFC2.h"
#endif

#include "0408MFC2Doc.h"
#include "0408MFC2View.h"
#include "MyDlg1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0408MFC2View

IMPLEMENT_DYNCREATE(CMy0408MFC2View, CView)

BEGIN_MESSAGE_MAP(CMy0408MFC2View, CView)
	ON_COMMAND(ID_ADD, &CMy0408MFC2View::OnAdd)
END_MESSAGE_MAP()

// CMy0408MFC2View ����/����

CMy0408MFC2View::CMy0408MFC2View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0408MFC2View::~CMy0408MFC2View()
{
}

BOOL CMy0408MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0408MFC2View ����

void CMy0408MFC2View::OnDraw(CDC* /*pDC*/)
{
	CMy0408MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy0408MFC2View ���

#ifdef _DEBUG
void CMy0408MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0408MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0408MFC2Doc* CMy0408MFC2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0408MFC2Doc)));
	return (CMy0408MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0408MFC2View ��Ϣ�������


void CMy0408MFC2View::OnAdd()
{
	// TODO: �ڴ���������������
	MyDlg1 *pD = new MyDlg1;
	pD->Create(IDD_DIALOG1);
	pD->ShowWindow(1);
}

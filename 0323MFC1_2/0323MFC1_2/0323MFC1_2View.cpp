
// 0323MFC1_2View.cpp : CMy0323MFC1_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0323MFC1_2.h"
#endif

#include "0323MFC1_2Doc.h"
#include "0323MFC1_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0323MFC1_2View

IMPLEMENT_DYNCREATE(CMy0323MFC1_2View, CView)

BEGIN_MESSAGE_MAP(CMy0323MFC1_2View, CView)
	ON_COMMAND(ID_SHOWCOLOR, &CMy0323MFC1_2View::OnShowcolor)
END_MESSAGE_MAP()

// CMy0323MFC1_2View ����/����

CMy0323MFC1_2View::CMy0323MFC1_2View()
{
	// TODO: �ڴ˴���ӹ������
	cs.SetSize(200);
}

CMy0323MFC1_2View::~CMy0323MFC1_2View()
{
}

BOOL CMy0323MFC1_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0323MFC1_2View ����

void CMy0323MFC1_2View::OnDraw(CDC* pDC)
{
	CMy0323MFC1_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	//RGB(rand() % 255, rand() % 255, rand() % 255)//��ɫ���
	for (int i = cs.GetSize() - 1; i >= 0; i--)
	{
		CPen NewPen(PS_SOLID, 2,RGB((i+1)*20,250-(i+1)*20, (i + 1) * 10)) , *pOldPen;//��ɫ����
		pOldPen = pDC->SelectObject(&NewPen);//����������,ͬʱ����ɻ���
		//pDC->SelectStockObject(NULL_BRUSH);//���������״���ڲ����Ϊ��ɫ
		pDC->Ellipse(cs.GetAt(i));//��Բ
		pDC->SelectObject(pOldPen);//��pDC�Ļ�ԭ���Ļ���
		NewPen.DeleteObject();//ɾ������
	}
		
}


// CMy0323MFC1_2View ���

#ifdef _DEBUG
void CMy0323MFC1_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0323MFC1_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0323MFC1_2Doc* CMy0323MFC1_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0323MFC1_2Doc)));
	return (CMy0323MFC1_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0323MFC1_2View ��Ϣ�������


void CMy0323MFC1_2View::OnShowcolor()
{
	// TODO: �ڴ���������������
	CRect cr;
	this->GetClientRect(&cr);//ȡ�ÿͻ���
	center = cr.CenterPoint();//���岢��ʼ���ͻ�������
	for (int i = 0; i < 10; i++)
	{
		CRect c1;
		c1.top = center.y - (i + 1) * 20; c1.left = center.x - (i + 1) * 20;
		c1.bottom = center.y + (i + 1) * 20; c1.right = center.x + (i + 1) * 20;
		cs.SetAt(i, c1);
	}
	Invalidate();

}

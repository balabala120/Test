
// 0420MFC2View.cpp : CMy0420MFC2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0420MFC2.h"
#endif

#include "0420MFC2Doc.h"
#include "0420MFC2View.h"
#include "MyDlg1.h"
#include "MyDlg2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0420MFC2View

IMPLEMENT_DYNCREATE(CMy0420MFC2View, CView)

BEGIN_MESSAGE_MAP(CMy0420MFC2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_Drawing, &CMy0420MFC2View::OnDrawing)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_Coloring, &CMy0420MFC2View::OnColoring)
END_MESSAGE_MAP()

// CMy0420MFC2View ����/����

CMy0420MFC2View::CMy0420MFC2View()
{
	// TODO: �ڴ˴���ӹ������
	cr = NULL;
	flag_mouse = 0;
	flag_choose = -1;
	mouse = NULL;
}

CMy0420MFC2View::~CMy0420MFC2View()
{
}

BOOL CMy0420MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0420MFC2View ����

void CMy0420MFC2View::OnDraw(CDC* pDC)
{
	CMy0420MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (flag_choose == 1)                               //��Բ��ѡ��
	{
		CPen newpen(PS_DOT, 1, RGB(0, 0, 0));       //PS_DOTΪ������ʽ
		CPen* pOldPen = pDC->SelectObject(&newpen);
		pDC->Rectangle(cr);                          //�������߾���  ��ʾ����Բ��ѡ��
		pDC->SelectObject(pOldPen);
	}
	
	pDC->Ellipse(cr);                    //�Ȼ����߾����ٻ���Բ

}


// CMy0420MFC2View ��ӡ

BOOL CMy0420MFC2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0420MFC2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0420MFC2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy0420MFC2View ���

#ifdef _DEBUG
void CMy0420MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0420MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0420MFC2Doc* CMy0420MFC2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0420MFC2Doc)));
	return (CMy0420MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0420MFC2View ��Ϣ�������


void CMy0420MFC2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
		flag_mouse = 1;
		mouse.x = point.x;
		mouse.y = point.y;
	
	CView::OnLButtonDown(nFlags, point);
}


void CMy0420MFC2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag_mouse = 0;
	CView::OnLButtonUp(nFlags, point);
}


void CMy0420MFC2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag_mouse == 1)
	{
		cr.left = mouse.x;                         //���������ʹ���϶��Ż�������Բ
		cr.top = mouse.y;
		cr.right = point.x;
		cr.bottom = point.y;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CMy0420MFC2View::OnDrawing()
{
	// TODO: �ڴ���������������
	MyDlg1  dlg;
	int r = dlg.DoModal();     
	if (r == IDOK) 
	{
		this->UpdateData(true);
		cr.top = dlg.y - dlg.b;
		cr.left = dlg.x - dlg.a;
		cr.bottom = dlg.y + dlg.b;
		cr.right = dlg.x + dlg.a;
		Invalidate();
	}
}


void CMy0420MFC2View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDblClk(nFlags, point);
}


void CMy0420MFC2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	HRGN ell = CreateEllipticRgn(cr.left, cr.top, cr.right, cr.bottom);//����һ����Բ���򲢷���������
	int i = PtInRegion(ell, point.x, point.y);//�ж�point�Ƿ�����Բ������  ���򷵻�ֵΪ1��
	if (i == 1)  flag_choose = -flag_choose;//�ı�ѡȡ״̬
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}


void CMy0420MFC2View::OnColoring()
{
	// TODO: �ڴ���������������
	MyDlg2 dlg;
	int r=dlg.DoModal();
	UpdateData(false);
	if (r == IDOK)
	{
		if (flag_choose == 1)                    //��ѡ�е���Բ��ɫ
		{
			CClientDC dc(this); // �õ�VIEW�Ŀͻ���DC
			CBrush brush(RGB(dlg.red,dlg.green, dlg.blue));//�����Լ���Ҫ�����ɫ
			CBrush *oldbrush;
			oldbrush = dc.SelectObject(&brush);//ѡ�µĻ�ˢ
			dc.Ellipse(cr);
			dc.SelectObject(oldbrush);//��ԭ���Ļ�ˢѡ��ȥ
		}
	}

}

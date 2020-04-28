
// 0420MFC2View.cpp : CMy0420MFC2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CMy0420MFC2View 构造/析构

CMy0420MFC2View::CMy0420MFC2View()
{
	// TODO: 在此处添加构造代码
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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0420MFC2View 绘制

void CMy0420MFC2View::OnDraw(CDC* pDC)
{
	CMy0420MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (flag_choose == 1)                               //椭圆被选中
	{
		CPen newpen(PS_DOT, 1, RGB(0, 0, 0));       //PS_DOT为虚线样式
		CPen* pOldPen = pDC->SelectObject(&newpen);
		pDC->Rectangle(cr);                          //画出虚线矩形  以示意椭圆被选中
		pDC->SelectObject(pOldPen);
	}
	
	pDC->Ellipse(cr);                    //先画虚线矩形再画椭圆

}


// CMy0420MFC2View 打印

BOOL CMy0420MFC2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0420MFC2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0420MFC2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0420MFC2View 诊断

#ifdef _DEBUG
void CMy0420MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0420MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0420MFC2Doc* CMy0420MFC2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0420MFC2Doc)));
	return (CMy0420MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0420MFC2View 消息处理程序


void CMy0420MFC2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
		flag_mouse = 1;
		mouse.x = point.x;
		mouse.y = point.y;
	
	CView::OnLButtonDown(nFlags, point);
}


void CMy0420MFC2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag_mouse = 0;
	CView::OnLButtonUp(nFlags, point);
}


void CMy0420MFC2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag_mouse == 1)
	{
		cr.left = mouse.x;                         //这两句可以使得拖动才会生成椭圆
		cr.top = mouse.y;
		cr.right = point.x;
		cr.bottom = point.y;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CMy0420MFC2View::OnDrawing()
{
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDblClk(nFlags, point);
}


void CMy0420MFC2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	HRGN ell = CreateEllipticRgn(cr.left, cr.top, cr.right, cr.bottom);//创建一个椭圆区域并返回区域句柄
	int i = PtInRegion(ell, point.x, point.y);//判断point是否在椭圆区域内  是则返回值为1。
	if (i == 1)  flag_choose = -flag_choose;//改变选取状态
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}


void CMy0420MFC2View::OnColoring()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg2 dlg;
	int r=dlg.DoModal();
	UpdateData(false);
	if (r == IDOK)
	{
		if (flag_choose == 1)                    //给选中的椭圆上色
		{
			CClientDC dc(this); // 得到VIEW的客户区DC
			CBrush brush(RGB(dlg.red,dlg.green, dlg.blue));//根据自己需要填充颜色
			CBrush *oldbrush;
			oldbrush = dc.SelectObject(&brush);//选新的画刷
			dc.Ellipse(cr);
			dc.SelectObject(oldbrush);//将原来的画刷选回去
		}
	}

}

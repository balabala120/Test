
// 0427MFC2View.cpp : CMy0427MFC2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0427MFC2.h"
#endif

#include "0427MFC2Doc.h"
#include "0427MFC2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0427MFC2View

IMPLEMENT_DYNCREATE(CMy0427MFC2View, CView)

BEGIN_MESSAGE_MAP(CMy0427MFC2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy0427MFC2View 构造/析构

CMy0427MFC2View::CMy0427MFC2View()
{
	// TODO: 在此处添加构造代码
	flag_mouse = 0;
	mouse = NULL;
}

CMy0427MFC2View::~CMy0427MFC2View()
{
}

BOOL CMy0427MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0427MFC2View 绘制

void CMy0427MFC2View::OnDraw(CDC* pDC)
{
	CMy0427MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	int n = pDoc->ca.GetCount();
	for (int i = 0; i < n; i++)
	{
		pDC->Ellipse(pDoc->ca[i]);
	}
	pDC->Ellipse(cr);

}


// CMy0427MFC2View 打印

BOOL CMy0427MFC2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0427MFC2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0427MFC2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0427MFC2View 诊断

#ifdef _DEBUG
void CMy0427MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0427MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0427MFC2Doc* CMy0427MFC2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0427MFC2Doc)));
	return (CMy0427MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0427MFC2View 消息处理程序


void CMy0427MFC2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag_mouse = 1;
	mouse = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMy0427MFC2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag_mouse == 1)
	{
		cr.left = mouse.x;        //这两句可以使得拖动才会生成椭圆
		cr.top = mouse.y;
		cr.right = point.x;
		cr.bottom = point.y;
		InvalidateRect(&cr);          //刷新指定区域
	}
	
	CView::OnMouseMove(nFlags, point);
}


void CMy0427MFC2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy0427MFC2Doc* pDoc = GetDocument();
	flag_mouse = 0;
	pDoc->ca.Add(cr);
	CView::OnLButtonUp(nFlags, point);
}

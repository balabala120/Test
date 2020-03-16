
// 0316MFCView.cpp : CMy0316MFCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0316MFC.h"
#endif

#include "0316MFCDoc.h"
#include "0316MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0316MFCView

IMPLEMENT_DYNCREATE(CMy0316MFCView, CView)

BEGIN_MESSAGE_MAP(CMy0316MFCView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy0316MFCView 构造/析构

CMy0316MFCView::CMy0316MFCView()
{
	// TODO: 在此处添加构造代码

}

CMy0316MFCView::~CMy0316MFCView()
{
}

BOOL CMy0316MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0316MFCView 绘制

void CMy0316MFCView::OnDraw(CDC* pDC)
{
	CMy0316MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->cr );
}


// CMy0316MFCView 打印

BOOL CMy0316MFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0316MFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0316MFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0316MFCView 诊断

#ifdef _DEBUG
void CMy0316MFCView::AssertValid() const
{
	CView::AssertValid();
}

void CMy0316MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0316MFCDoc* CMy0316MFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0316MFCDoc)));
	return (CMy0316MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy0316MFCView 消息处理程序


void CMy0316MFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy0316MFCDoc* pDoc = GetDocument();
	pDoc->cr.left = point.x;
	pDoc->cr.top = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void CMy0316MFCView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy0316MFCDoc* pDoc = GetDocument();
	pDoc->cr.right  = point.x;
	pDoc->cr.bottom = point.y;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonUp(nFlags, point);
}


void CMy0316MFCView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s;
	s.Format(_T("x=%d,y=%d"),point.x,point.y);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnMouseMove(nFlags, point);
}


// 0310MFC1View.cpp : CMy0310MFC1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0310MFC1.h"
#endif

#include "0310MFC1Doc.h"
#include "0310MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0310MFC1View

IMPLEMENT_DYNCREATE(CMy0310MFC1View, CView)

BEGIN_MESSAGE_MAP(CMy0310MFC1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy0310MFC1View 构造/析构

CMy0310MFC1View::CMy0310MFC1View()
{
	// TODO: 在此处添加构造代码

}

CMy0310MFC1View::~CMy0310MFC1View()
{
}

BOOL CMy0310MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0310MFC1View 绘制

void CMy0310MFC1View::OnDraw(CDC* /*pDC*/)
{
	CMy0310MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy0310MFC1View 打印

BOOL CMy0310MFC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0310MFC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0310MFC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0310MFC1View 诊断

#ifdef _DEBUG
void CMy0310MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0310MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0310MFC1Doc* CMy0310MFC1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0310MFC1Doc)));
	return (CMy0310MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0310MFC1View 消息处理程序


void CMy0310MFC1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy0310MFC1Doc* pDoc = GetDocument();
	CString s1;
	s1.Format(pDoc->Ldown);
	
	CClientDC dc(this);
	dc.TextOutW(point.x, point.y, s1);

	CView::OnLButtonDown(nFlags, point);
}


void CMy0310MFC1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy0310MFC1Doc* pDoc = GetDocument();
	CString s2;
	s2.Format(pDoc->Lup);

	CClientDC dc(this);
	dc.TextOutW(point.x, point.y, s2);

	CView::OnLButtonUp(nFlags, point);
}

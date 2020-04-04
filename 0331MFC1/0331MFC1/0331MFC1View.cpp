
// 0331MFC1View.cpp : CMy0331MFC1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0331MFC1.h"
#endif

#include "0331MFC1Doc.h"
#include "0331MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0331MFC1View

IMPLEMENT_DYNCREATE(CMy0331MFC1View, CView)

BEGIN_MESSAGE_MAP(CMy0331MFC1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0331MFC1View 构造/析构

CMy0331MFC1View::CMy0331MFC1View()
{
	// TODO: 在此处添加构造代码
	s = "";
	insert = 0;
}

CMy0331MFC1View::~CMy0331MFC1View()
{
}

BOOL CMy0331MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0331MFC1View 绘制

void CMy0331MFC1View::OnDraw(CDC* pDC)
{
	CMy0331MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(20, 30, 1000, 400);



}


// CMy0331MFC1View 打印

BOOL CMy0331MFC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0331MFC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0331MFC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0331MFC1View 诊断

#ifdef _DEBUG
void CMy0331MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0331MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0331MFC1Doc* CMy0331MFC1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0331MFC1Doc)));
	return (CMy0331MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0331MFC1View 消息处理程序


void CMy0331MFC1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	s += (char)nChar;
	dc.TextOutW(30, 40, s);
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMy0331MFC1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	insert = point;//获取插入位置
	CView::OnLButtonDown(nFlags, point);
}

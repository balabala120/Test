
// 0310MFC2_2View.cpp : CMy0310MFC2_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0310MFC2_2.h"
#endif

#include "0310MFC2_2Doc.h"
#include "0310MFC2_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0310MFC2_2View

IMPLEMENT_DYNCREATE(CMy0310MFC2_2View, CView)

BEGIN_MESSAGE_MAP(CMy0310MFC2_2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0310MFC2_2View 构造/析构

CMy0310MFC2_2View::CMy0310MFC2_2View()
{
	// TODO: 在此处添加构造代码
	

}

CMy0310MFC2_2View::~CMy0310MFC2_2View()
{
}

BOOL CMy0310MFC2_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0310MFC2_2View 绘制

void CMy0310MFC2_2View::OnDraw(CDC* pDC)
{
	CMy0310MFC2_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	for (int i = 0; i < pDoc->ca.GetSize(); i++)
		pDC->Ellipse(pDoc->ca.GetAt(i));
}


// CMy0310MFC2_2View 打印

BOOL CMy0310MFC2_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0310MFC2_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0310MFC2_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0310MFC2_2View 诊断

#ifdef _DEBUG
void CMy0310MFC2_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0310MFC2_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0310MFC2_2Doc* CMy0310MFC2_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0310MFC2_2Doc)));
	return (CMy0310MFC2_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0310MFC2_2View 消息处理程序


void CMy0310MFC2_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int a = rand() % 150 + 5;
	int b = rand() % 150 + 5;
	CRect cr(point.x - a, point.y - b, point.x + a, point.y + b);
	CMy0310MFC2_2Doc* pDoc = GetDocument();
	pDoc->ca.Add(cr);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

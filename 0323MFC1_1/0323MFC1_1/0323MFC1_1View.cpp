
// 0323MFC1_1View.cpp : CMy0323MFC1_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0323MFC1_1.h"
#endif

#include "0323MFC1_1Doc.h"
#include "0323MFC1_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0323MFC1_1View

IMPLEMENT_DYNCREATE(CMy0323MFC1_1View, CView)

BEGIN_MESSAGE_MAP(CMy0323MFC1_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOWCIRCLES, &CMy0323MFC1_1View::OnShowcircles)
END_MESSAGE_MAP()

// CMy0323MFC1_1View 构造/析构

CMy0323MFC1_1View::CMy0323MFC1_1View()
{
	// TODO: 在此处添加构造代码
	cs.SetSize(200);
	
	
}

CMy0323MFC1_1View::~CMy0323MFC1_1View()
{
}

BOOL CMy0323MFC1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0323MFC1_1View 绘制

void CMy0323MFC1_1View::OnDraw(CDC* pDC)
{
	CMy0323MFC1_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	for (int i = cs.GetSize()-1; i >= 0; i--)
		pDC->Ellipse(cs.GetAt(i));

	
	
}


// CMy0323MFC1_1View 打印

BOOL CMy0323MFC1_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0323MFC1_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0323MFC1_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0323MFC1_1View 诊断

#ifdef _DEBUG
void CMy0323MFC1_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0323MFC1_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0323MFC1_1Doc* CMy0323MFC1_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0323MFC1_1Doc)));
	return (CMy0323MFC1_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0323MFC1_1View 消息处理程序


void CMy0323MFC1_1View::OnShowcircles()
{
	// TODO: 在此添加命令处理程序代码
	CRect cr;
	this->GetClientRect(&cr);//取得客户区
	center = cr.CenterPoint();//定义并初始化客户区中心
	for (int i = 0; i < 10; i++)
	{
		CRect c1;
		c1.top = center.y -(i+1)* 20; c1.left = center.x - (i + 1) * 20;
		c1.bottom = center.y + (i + 1) * 20; c1.right = center.x + (i + 1) * 20;
		cs.SetAt(i,c1);
	}
	Invalidate();
	
	//CRect c1(center.y - 50, center.x - 50, center.y + 50, center.x + 50);
	//CRect c2(center.y - 100,center.x - 100,center.y + 100,center.x + 100);
	//cs.SetAt(1,c2);
	
}

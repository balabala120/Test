
// 0323MFC1_2View.cpp : CMy0323MFC1_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMy0323MFC1_2View 构造/析构

CMy0323MFC1_2View::CMy0323MFC1_2View()
{
	// TODO: 在此处添加构造代码
	cs.SetSize(200);
}

CMy0323MFC1_2View::~CMy0323MFC1_2View()
{
}

BOOL CMy0323MFC1_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0323MFC1_2View 绘制

void CMy0323MFC1_2View::OnDraw(CDC* pDC)
{
	CMy0323MFC1_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	//RGB(rand() % 255, rand() % 255, rand() % 255)//颜色随机
	for (int i = cs.GetSize() - 1; i >= 0; i--)
	{
		CPen NewPen(PS_SOLID, 2,RGB((i+1)*20,250-(i+1)*20, (i + 1) * 10)) , *pOldPen;//颜色渐变
		pOldPen = pDC->SelectObject(&NewPen);//添加这个画笔,同时保存旧画笔
		//pDC->SelectStockObject(NULL_BRUSH);//设置这个形状的内部填充为无色
		pDC->Ellipse(cs.GetAt(i));//画圆
		pDC->SelectObject(pOldPen);//将pDC改回原来的画笔
		NewPen.DeleteObject();//删除画笔
	}
		
}


// CMy0323MFC1_2View 诊断

#ifdef _DEBUG
void CMy0323MFC1_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0323MFC1_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0323MFC1_2Doc* CMy0323MFC1_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0323MFC1_2Doc)));
	return (CMy0323MFC1_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0323MFC1_2View 消息处理程序


void CMy0323MFC1_2View::OnShowcolor()
{
	// TODO: 在此添加命令处理程序代码
	CRect cr;
	this->GetClientRect(&cr);//取得客户区
	center = cr.CenterPoint();//定义并初始化客户区中心
	for (int i = 0; i < 10; i++)
	{
		CRect c1;
		c1.top = center.y - (i + 1) * 20; c1.left = center.x - (i + 1) * 20;
		c1.bottom = center.y + (i + 1) * 20; c1.right = center.x + (i + 1) * 20;
		cs.SetAt(i, c1);
	}
	Invalidate();

}

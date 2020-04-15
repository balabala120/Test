
// 0408MFC4View.cpp : CMy0408MFC4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0408MFC4.h"
#endif

#include "0408MFC4Doc.h"
#include "0408MFC4View.h"
#include "MyDlg1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0408MFC4View

IMPLEMENT_DYNCREATE(CMy0408MFC4View, CView)

BEGIN_MESSAGE_MAP(CMy0408MFC4View, CView)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMy0408MFC4View 构造/析构

CMy0408MFC4View::CMy0408MFC4View()
{
	// TODO: 在此处添加构造代码

}

CMy0408MFC4View::~CMy0408MFC4View()
{
}

BOOL CMy0408MFC4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0408MFC4View 绘制

void CMy0408MFC4View::OnDraw(CDC* /*pDC*/)
{
	CMy0408MFC4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s ("客户区双击弹出对话框");
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);

}


// CMy0408MFC4View 诊断

#ifdef _DEBUG
void CMy0408MFC4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0408MFC4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0408MFC4Doc* CMy0408MFC4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0408MFC4Doc)));
	return (CMy0408MFC4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0408MFC4View 消息处理程序


void CMy0408MFC4View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MyDlg1 *pD = new MyDlg1;
	pD->s1 = "";//对三个编辑控件对应的变量初始化
	pD->a = 0;
	pD->s2 = "";
	pD->Create(IDD_DIALOG1);
	pD->ShowWindow(1); 

	CView::OnLButtonDblClk(nFlags, point);
}

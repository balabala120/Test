
// 0428MFCwindllView.cpp : CMy0428MFCwindllView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0428MFCwindll.h"
#endif

#include "0428MFCwindllDoc.h"
#include "0428MFCwindllView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "w32.h"
#include "Win32Dll.h"
// CMy0428MFCwindllView

IMPLEMENT_DYNCREATE(CMy0428MFCwindllView, CView)

BEGIN_MESSAGE_MAP(CMy0428MFCwindllView, CView)
END_MESSAGE_MAP()

// CMy0428MFCwindllView 构造/析构

CMy0428MFCwindllView::CMy0428MFCwindllView()
{
	// TODO: 在此处添加构造代码

}

CMy0428MFCwindllView::~CMy0428MFCwindllView()
{
}

BOOL CMy0428MFCwindllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0428MFCwindllView 绘制

void CMy0428MFCwindllView::OnDraw(CDC* pDC)
{
	CMy0428MFCwindllDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	s= pchar();
	pDC->TextOutW(200,200,s);

	CString ss;
	ss.Format(_T("动态库返回的值是 %d"),GetInt());
	pDC->TextOutW(200, 230, ss);
}


// CMy0428MFCwindllView 诊断

#ifdef _DEBUG
void CMy0428MFCwindllView::AssertValid() const
{
	CView::AssertValid();
}

void CMy0428MFCwindllView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0428MFCwindllDoc* CMy0428MFCwindllView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0428MFCwindllDoc)));
	return (CMy0428MFCwindllDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy0428MFCwindllView 消息处理程序

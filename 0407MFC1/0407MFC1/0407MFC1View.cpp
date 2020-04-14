
// 0407MFC1View.cpp : CMy0407MFC1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0407MFC1.h"
#endif

#include "0407MFC1Doc.h"
#include "0407MFC1View.h"
#include "MyDlg1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0407MFC1View

IMPLEMENT_DYNCREATE(CMy0407MFC1View, CView)

BEGIN_MESSAGE_MAP(CMy0407MFC1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popout, &CMy0407MFC1View::Onpopout)
END_MESSAGE_MAP()

// CMy0407MFC1View 构造/析构

CMy0407MFC1View::CMy0407MFC1View()
{
	// TODO: 在此处添加构造代码

}

CMy0407MFC1View::~CMy0407MFC1View()
{
}

BOOL CMy0407MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0407MFC1View 绘制

void CMy0407MFC1View::OnDraw(CDC* /*pDC*/)
{
	CMy0407MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy0407MFC1View 打印

BOOL CMy0407MFC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0407MFC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0407MFC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0407MFC1View 诊断

#ifdef _DEBUG
void CMy0407MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0407MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0407MFC1Doc* CMy0407MFC1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0407MFC1Doc)));
	return (CMy0407MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0407MFC1View 消息处理程序


void CMy0407MFC1View::Onpopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg1 dlg;
	int r = dlg.DoModal();
	if (r == IDOK) 
	{
		CString s ("您已退出对话框");
		CClientDC dc(this);
		dc.TextOutW(200, 200,s );
	}
}

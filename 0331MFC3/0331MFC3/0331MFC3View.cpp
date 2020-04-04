
// 0331MFC3View.cpp : CMy0331MFC3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0331MFC3.h"
#endif

#include "0331MFC3Doc.h"
#include "0331MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0331MFC3View

IMPLEMENT_DYNCREATE(CMy0331MFC3View, CView)

BEGIN_MESSAGE_MAP(CMy0331MFC3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMy0331MFC3View 构造/析构

CMy0331MFC3View::CMy0331MFC3View()
{
	// TODO: 在此处添加构造代码
	cr.top = 100;cr.left=100;
	cr.bottom = 500; cr.right = 500;
}

CMy0331MFC3View::~CMy0331MFC3View()
{
}

BOOL CMy0331MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0331MFC3View 绘制

void CMy0331MFC3View::OnDraw(CDC* pDC)
{
	CMy0331MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(cr);
}


// CMy0331MFC3View 打印

BOOL CMy0331MFC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0331MFC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0331MFC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0331MFC3View 诊断

#ifdef _DEBUG
void CMy0331MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0331MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0331MFC3Doc* CMy0331MFC3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0331MFC3Doc)));
	return (CMy0331MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0331MFC3View 消息处理程序

int i=0;//用于标志第几行
void CMy0331MFC3View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	s += (char)nChar;
	CSize sz = dc.GetTextExtent(s);
	if (cr.left + 5 + sz.cx >= cr.right - 10)//判断是否即将到达框架cr边缘，如果是则换行
	{
		i++;//i用来标志第几行 
			//dc.TextOutW(500, 500, _T("即将超出"));
		s.Empty();
		s += (char)nChar;
		sz = dc.GetTextExtent(s);
	}
	dc.TextOutW(cr.left+5,cr.top+i*sz.cy+5,s);

	CView::OnChar(nChar, nRepCnt, nFlags);
}

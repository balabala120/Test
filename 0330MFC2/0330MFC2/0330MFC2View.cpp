
// 0330MFC2View.cpp : CMy0330MFC2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0330MFC2.h"
#endif

#include "0330MFC2Doc.h"
#include "0330MFC2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0330MFC2View

IMPLEMENT_DYNCREATE(CMy0330MFC2View, CView)

BEGIN_MESSAGE_MAP(CMy0330MFC2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMy0330MFC2View::OnFileOpen)
END_MESSAGE_MAP()

// CMy0330MFC2View 构造/析构

CMy0330MFC2View::CMy0330MFC2View()
{
	// TODO: 在此处添加构造代码
	flag = 0;
}

CMy0330MFC2View::~CMy0330MFC2View()
{
}

BOOL CMy0330MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0330MFC2View 绘制

void CMy0330MFC2View::OnDraw(CDC* pDC)
{
	CMy0330MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cc;
	GetClientRect(&cc);    //取得客户区给cc
	if(flag==1)
	{ 
		
		pDC->TextOutW(0, 0, pDoc->filename);
		pDoc->img.Draw(pDC->m_hDC, cc.CenterPoint().x - pDoc->img.GetWidth()/ 2, cc.CenterPoint().y - pDoc->img.GetHeight() / 2, pDoc->img.GetWidth(), pDoc->img.GetHeight());
		
	}
	
}


// CMy0330MFC2View 打印

BOOL CMy0330MFC2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0330MFC2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0330MFC2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0330MFC2View 诊断

#ifdef _DEBUG
void CMy0330MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0330MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0330MFC2Doc* CMy0330MFC2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0330MFC2Doc)));
	return (CMy0330MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0330MFC2View 消息处理程序


void CMy0330MFC2View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CMy0330MFC2Doc* pDoc = GetDocument();
	CFileDialog cfd(true);  //建立对象
	int r = cfd.DoModal();  //弹出对话框
	if (r == IDOK)        //如果退出对话框时选项为OK的话
	{
		pDoc->filename = cfd.GetPathName();
		pDoc->img.Load(pDoc->filename);
		flag = 1;
		Invalidate();
	}
}

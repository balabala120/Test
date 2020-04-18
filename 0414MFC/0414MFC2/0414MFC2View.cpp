
// 0414MFC2View.cpp : CMy0414MFC2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0414MFC2.h"
#endif

#include "0414MFC2Doc.h"
#include "0414MFC2View.h"
#include "Mydlg1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0414MFC2View

IMPLEMENT_DYNCREATE(CMy0414MFC2View, CView)

BEGIN_MESSAGE_MAP(CMy0414MFC2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_ShowFname, &CMy0414MFC2View::OnShowfname)
END_MESSAGE_MAP()

// CMy0414MFC2View 构造/析构

CMy0414MFC2View::CMy0414MFC2View()
{
	// TODO: 在此处添加构造代码
	filename = "";
}

CMy0414MFC2View::~CMy0414MFC2View()
{
}

BOOL CMy0414MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0414MFC2View 绘制

void CMy0414MFC2View::OnDraw(CDC* pDC)
{
	CMy0414MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s1("(1)双击鼠标左键, 弹出打开文件对话框，从中选择任一个文件名， 在客户区显示该文件名;");
	CString s2("(2)然后点击“视图-显示已选取文件名”， 弹出一个对话框，使该文件名在对话框中的一个编辑控件中显示出来。");
	pDC->TextOutW(10, 10, s1);
	pDC->TextOutW(10, 40, s2);
}


// CMy0414MFC2View 打印

BOOL CMy0414MFC2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0414MFC2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0414MFC2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0414MFC2View 诊断

#ifdef _DEBUG
void CMy0414MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0414MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0414MFC2Doc* CMy0414MFC2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0414MFC2Doc)));
	return (CMy0414MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0414MFC2View 消息处理程序


void CMy0414MFC2View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		filename = cfd.GetFileName();
		dc.TextOutW(200, 200, filename);
	}

	CView::OnLButtonDblClk(nFlags, point);
}


void CMy0414MFC2View::OnShowfname()
{
	// TODO: 在此添加命令处理程序代码
	Mydlg1 dlg;
	dlg.fname = filename;
	UpdateData(false);
	dlg.DoModal();//先更新数据再显示对话框
}


// 0414MFC3View.cpp : CMy0414MFC3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0414MFC3.h"
#endif

#include "0414MFC3Doc.h"
#include "0414MFC3View.h"
#include "MyDlg2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0414MFC3View

IMPLEMENT_DYNCREATE(CMy0414MFC3View, CView)

BEGIN_MESSAGE_MAP(CMy0414MFC3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ShowFileName, &CMy0414MFC3View::OnShowfilename)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMy0414MFC3View 构造/析构

CMy0414MFC3View::CMy0414MFC3View()
{
	// TODO: 在此处添加构造代码
	fname = "";
	
}

CMy0414MFC3View::~CMy0414MFC3View()
{
}

BOOL CMy0414MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0414MFC3View 绘制

void CMy0414MFC3View::OnDraw(CDC* pDC)
{
	CMy0414MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s1("(1)双击鼠标左键, 弹出打开文件对话框，从中选择任一个文件名， 在客户区显示该文件名;");
	CString s2("(2)然后点击“视图-显示已选取文件名”， 弹出一个对话框，使该文件名在对话框中的一个编辑控件中显示出来。");
	CString s3("(3)把文件名在对话框中的一个列表框中显示出来");
	pDC->TextOutW(10, 10, s1);
	pDC->TextOutW(10, 40, s2);
	pDC->TextOutW(10, 70, s3);
}


// CMy0414MFC3View 打印

BOOL CMy0414MFC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0414MFC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0414MFC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0414MFC3View 诊断

#ifdef _DEBUG
void CMy0414MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0414MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0414MFC3Doc* CMy0414MFC3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0414MFC3Doc)));
	return (CMy0414MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0414MFC3View 消息处理程序


void CMy0414MFC3View::OnShowfilename()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg2 *dlg = new MyDlg2();       //非模式对话框，有一个列表框LBox和一个编辑控件filename
	dlg->filename = fname;            //fname是文件名（全局变量字符串）
	UpdateData(false);                //先更新数据再创建窗口
	dlg->Create(IDD_DIALOG1);
	dlg->LBox.InsertString(-1,fname);  //但是这句要在创建窗口之后
	dlg->ShowWindow(1);
}


void CMy0414MFC3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		fname = cfd.GetFileName();
		dc.TextOutW(200, 200, fname);
	}
	CView::OnLButtonDblClk(nFlags, point);
}

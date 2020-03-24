
// 0324MFC2View.cpp : CMy0324MFC2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0324MFC2.h"
#endif

#include "0324MFC2Doc.h"
#include "0324MFC2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0324MFC2View

IMPLEMENT_DYNCREATE(CMy0324MFC2View, CView)

BEGIN_MESSAGE_MAP(CMy0324MFC2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy0324MFC2View 构造/析构

CMy0324MFC2View::CMy0324MFC2View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;//初始化
	bitmap1_car.LoadBitmap(IDCANCEL);
	bitmap1_car.GetBitmap(&BM);
		bitmap1_width = BM.bmWidth;
	bitmap1_height =BM.bmHeight;

	
}

CMy0324MFC2View::~CMy0324MFC2View()
{
}

BOOL CMy0324MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0324MFC2View 绘制

void CMy0324MFC2View::OnDraw(CDC* pDC)
{
	CMy0324MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC MemDC;//绘图
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(bitmap1_car);
	pDC->BitBlt(0, 0, bitmap1_width, bitmap1_height, &MemDC, 0, 0,SRCCOPY);

}


// CMy0324MFC2View 打印

BOOL CMy0324MFC2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0324MFC2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0324MFC2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0324MFC2View 诊断

#ifdef _DEBUG
void CMy0324MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0324MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0324MFC2Doc* CMy0324MFC2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0324MFC2Doc)));
	return (CMy0324MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0324MFC2View 消息处理程序

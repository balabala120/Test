
// 0414MFC3View.h : CMy0414MFC3View 类的接口
//

#pragma once

#include "MyDlg2.h"
class CMy0414MFC3View : public CView
{
protected: // 仅从序列化创建
	CMy0414MFC3View();
	DECLARE_DYNCREATE(CMy0414MFC3View)

// 特性
public:
	CMy0414MFC3Doc* GetDocument() const;
	CString fname;
	MyDlg2 *dlg;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy0414MFC3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowfilename();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0414MFC3View.cpp 中的调试版本
inline CMy0414MFC3Doc* CMy0414MFC3View::GetDocument() const
   { return reinterpret_cast<CMy0414MFC3Doc*>(m_pDocument); }
#endif



// 0407MFC2View.h : CMy0407MFC2View 类的接口
//

#pragma once
#include "MyDlg1.h"

class CMy0407MFC2View : public CView
{
protected: // 仅从序列化创建
	CMy0407MFC2View();
	DECLARE_DYNCREATE(CMy0407MFC2View)
	
// 特性
public:
	CMy0407MFC2Doc* GetDocument() const;

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
	virtual ~CMy0407MFC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onpop();
	
};

#ifndef _DEBUG  // 0407MFC2View.cpp 中的调试版本
inline CMy0407MFC2Doc* CMy0407MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0407MFC2Doc*>(m_pDocument); }
#endif


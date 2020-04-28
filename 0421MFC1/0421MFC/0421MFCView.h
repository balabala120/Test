
// 0421MFCView.h : CMy0421MFCView 类的接口
//

#pragma once


class CMy0421MFCView : public CView
{
protected: // 仅从序列化创建
	CMy0421MFCView();
	DECLARE_DYNCREATE(CMy0421MFCView)

// 特性
public:
	CMy0421MFCDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy0421MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSave();
	afx_msg void OnShow();
};

#ifndef _DEBUG  // 0421MFCView.cpp 中的调试版本
inline CMy0421MFCDoc* CMy0421MFCView::GetDocument() const
   { return reinterpret_cast<CMy0421MFCDoc*>(m_pDocument); }
#endif


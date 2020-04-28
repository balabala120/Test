
// 0428MFCwindllView.h : CMy0428MFCwindllView 类的接口
//

#pragma once


class CMy0428MFCwindllView : public CView
{
protected: // 仅从序列化创建
	CMy0428MFCwindllView();
	DECLARE_DYNCREATE(CMy0428MFCwindllView)

// 特性
public:
	CMy0428MFCwindllDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy0428MFCwindllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 0428MFCwindllView.cpp 中的调试版本
inline CMy0428MFCwindllDoc* CMy0428MFCwindllView::GetDocument() const
   { return reinterpret_cast<CMy0428MFCwindllDoc*>(m_pDocument); }
#endif



// 0408MFC2View.h : CMy0408MFC2View 类的接口
//

#pragma once


class CMy0408MFC2View : public CView
{
protected: // 仅从序列化创建
	CMy0408MFC2View();
	DECLARE_DYNCREATE(CMy0408MFC2View)

// 特性
public:
	CMy0408MFC2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy0408MFC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAdd();
};

#ifndef _DEBUG  // 0408MFC2View.cpp 中的调试版本
inline CMy0408MFC2Doc* CMy0408MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0408MFC2Doc*>(m_pDocument); }
#endif



// 0323MFC1_2View.h : CMy0323MFC1_2View 类的接口
//

#pragma once


class CMy0323MFC1_2View : public CView
{
protected: // 仅从序列化创建
	CMy0323MFC1_2View();
	DECLARE_DYNCREATE(CMy0323MFC1_2View)

// 特性
public:
	CMy0323MFC1_2Doc* GetDocument() const;
	CArray<CRect, CRect& > cs;//数组
	CPoint center;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy0323MFC1_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowcolor();
};

#ifndef _DEBUG  // 0323MFC1_2View.cpp 中的调试版本
inline CMy0323MFC1_2Doc* CMy0323MFC1_2View::GetDocument() const
   { return reinterpret_cast<CMy0323MFC1_2Doc*>(m_pDocument); }
#endif


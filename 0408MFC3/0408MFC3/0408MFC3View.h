
// 0408MFC3View.h : CMy0408MFC3View 类的接口
//

#pragma once


class CMy0408MFC3View : public CView
{
protected: // 仅从序列化创建
	CMy0408MFC3View();
	DECLARE_DYNCREATE(CMy0408MFC3View)

// 特性
public:
	CMy0408MFC3Doc* GetDocument() const;
	CRect cr;
	int flag;//用于控制移动和停止
	int rl;//用于标记方向  0为向右移动  1为向左移动
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy0408MFC3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0408MFC3View.cpp 中的调试版本
inline CMy0408MFC3Doc* CMy0408MFC3View::GetDocument() const
   { return reinterpret_cast<CMy0408MFC3Doc*>(m_pDocument); }
#endif


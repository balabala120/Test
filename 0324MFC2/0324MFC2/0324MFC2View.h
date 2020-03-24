
// 0324MFC2View.h : CMy0324MFC2View 类的接口
//

#pragma once


class CMy0324MFC2View : public CView
{
protected: // 仅从序列化创建
	CMy0324MFC2View();
	DECLARE_DYNCREATE(CMy0324MFC2View)

// 特性
public:
	CMy0324MFC2Doc* GetDocument() const;
	CBitmap bitmap1_car;//位图对象
	int bitmap1_width;//存储位图宽的数据成员
	int bitmap1_height;
	

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
	virtual ~CMy0324MFC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 0324MFC2View.cpp 中的调试版本
inline CMy0324MFC2Doc* CMy0324MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0324MFC2Doc*>(m_pDocument); }
#endif


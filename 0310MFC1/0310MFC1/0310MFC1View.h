
// 0310MFC1View.h : CMy0310MFC1View ��Ľӿ�
//

#pragma once


class CMy0310MFC1View : public CView
{
protected: // �������л�����
	CMy0310MFC1View();
	DECLARE_DYNCREATE(CMy0310MFC1View)

// ����
public:
	CMy0310MFC1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy0310MFC1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0310MFC1View.cpp �еĵ��԰汾
inline CMy0310MFC1Doc* CMy0310MFC1View::GetDocument() const
   { return reinterpret_cast<CMy0310MFC1Doc*>(m_pDocument); }
#endif



// 0310MFC2_1View.h : CMy0310MFC2_1View ��Ľӿ�
//

#pragma once


class CMy0310MFC2_1View : public CView
{
protected: // �������л�����
	CMy0310MFC2_1View();
	DECLARE_DYNCREATE(CMy0310MFC2_1View)

// ����
public:
	CMy0310MFC2_1Doc* GetDocument() const;

// ����
public:
	CArray<CRect, CRect &> ca;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy0310MFC2_1View();
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
};

#ifndef _DEBUG  // 0310MFC2_1View.cpp �еĵ��԰汾
inline CMy0310MFC2_1Doc* CMy0310MFC2_1View::GetDocument() const
   { return reinterpret_cast<CMy0310MFC2_1Doc*>(m_pDocument); }
#endif


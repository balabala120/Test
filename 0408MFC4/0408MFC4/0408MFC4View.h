
// 0408MFC4View.h : CMy0408MFC4View ��Ľӿ�
//

#pragma once


class CMy0408MFC4View : public CView
{
protected: // �������л�����
	CMy0408MFC4View();
	DECLARE_DYNCREATE(CMy0408MFC4View)

// ����
public:
	CMy0408MFC4Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy0408MFC4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0408MFC4View.cpp �еĵ��԰汾
inline CMy0408MFC4Doc* CMy0408MFC4View::GetDocument() const
   { return reinterpret_cast<CMy0408MFC4Doc*>(m_pDocument); }
#endif


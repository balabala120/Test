
// 0408MFC1View.h : CMy0408MFC1View ��Ľӿ�
//

#pragma once


class CMy0408MFC1View : public CView
{
protected: // �������л�����
	CMy0408MFC1View();
	DECLARE_DYNCREATE(CMy0408MFC1View)

// ����
public:
	CMy0408MFC1Doc* GetDocument() const;
	CRect cr;
	CPoint mouse;//���ڼ�¼����ƶ�����
	int flag;//���ڱ���������Ƿ���
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy0408MFC1View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0408MFC1View.cpp �еĵ��԰汾
inline CMy0408MFC1Doc* CMy0408MFC1View::GetDocument() const
   { return reinterpret_cast<CMy0408MFC1Doc*>(m_pDocument); }
#endif


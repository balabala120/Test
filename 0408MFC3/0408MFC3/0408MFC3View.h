
// 0408MFC3View.h : CMy0408MFC3View ��Ľӿ�
//

#pragma once


class CMy0408MFC3View : public CView
{
protected: // �������л�����
	CMy0408MFC3View();
	DECLARE_DYNCREATE(CMy0408MFC3View)

// ����
public:
	CMy0408MFC3Doc* GetDocument() const;
	CRect cr;
	int flag;//���ڿ����ƶ���ֹͣ
	int rl;//���ڱ�Ƿ���  0Ϊ�����ƶ�  1Ϊ�����ƶ�
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy0408MFC3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0408MFC3View.cpp �еĵ��԰汾
inline CMy0408MFC3Doc* CMy0408MFC3View::GetDocument() const
   { return reinterpret_cast<CMy0408MFC3Doc*>(m_pDocument); }
#endif


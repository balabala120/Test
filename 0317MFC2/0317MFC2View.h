
// 0317MFC2View.h : CMy0317MFC2View ��Ľӿ�
//

#pragma once


class CMy0317MFC2View : public CView
{
protected: // �������л�����
	CMy0317MFC2View();
	DECLARE_DYNCREATE(CMy0317MFC2View)

// ����
public:
	CMy0317MFC2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy0317MFC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0317MFC2View.cpp �еĵ��԰汾
inline CMy0317MFC2Doc* CMy0317MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0317MFC2Doc*>(m_pDocument); }
#endif



// 0310MFC2View.h : CMy0310MFC2View ��Ľӿ�
//

#pragma once


class CMy0310MFC2View : public CView
{
protected: // �������л�����
	CMy0310MFC2View();
	DECLARE_DYNCREATE(CMy0310MFC2View)

// ����
public:
	CMy0310MFC2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy0310MFC2View();
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

#ifndef _DEBUG  // 0310MFC2View.cpp �еĵ��԰汾
inline CMy0310MFC2Doc* CMy0310MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0310MFC2Doc*>(m_pDocument); }
#endif


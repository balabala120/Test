
// 0323MFC1_2View.h : CMy0323MFC1_2View ��Ľӿ�
//

#pragma once


class CMy0323MFC1_2View : public CView
{
protected: // �������л�����
	CMy0323MFC1_2View();
	DECLARE_DYNCREATE(CMy0323MFC1_2View)

// ����
public:
	CMy0323MFC1_2Doc* GetDocument() const;
	CArray<CRect, CRect& > cs;//����
	CPoint center;
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy0323MFC1_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowcolor();
};

#ifndef _DEBUG  // 0323MFC1_2View.cpp �еĵ��԰汾
inline CMy0323MFC1_2Doc* CMy0323MFC1_2View::GetDocument() const
   { return reinterpret_cast<CMy0323MFC1_2Doc*>(m_pDocument); }
#endif


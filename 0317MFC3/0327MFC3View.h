
// 0327MFC3View.h : CMy0327MFC3View ��Ľӿ�
//

#pragma once


class CMy0327MFC3View : public CView
{
protected: // �������л�����
	CMy0327MFC3View();
	DECLARE_DYNCREATE(CMy0327MFC3View)

// ����
public:
	CMy0327MFC3Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy0327MFC3View();
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
};

#ifndef _DEBUG  // 0327MFC3View.cpp �еĵ��԰汾
inline CMy0327MFC3Doc* CMy0327MFC3View::GetDocument() const
   { return reinterpret_cast<CMy0327MFC3Doc*>(m_pDocument); }
#endif



// 0421MFCView.h : CMy0421MFCView ��Ľӿ�
//

#pragma once


class CMy0421MFCView : public CView
{
protected: // �������л�����
	CMy0421MFCView();
	DECLARE_DYNCREATE(CMy0421MFCView)

// ����
public:
	CMy0421MFCDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy0421MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSave();
	afx_msg void OnShow();
};

#ifndef _DEBUG  // 0421MFCView.cpp �еĵ��԰汾
inline CMy0421MFCDoc* CMy0421MFCView::GetDocument() const
   { return reinterpret_cast<CMy0421MFCDoc*>(m_pDocument); }
#endif


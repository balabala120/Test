
// 0428MFCwindllView.h : CMy0428MFCwindllView ��Ľӿ�
//

#pragma once


class CMy0428MFCwindllView : public CView
{
protected: // �������л�����
	CMy0428MFCwindllView();
	DECLARE_DYNCREATE(CMy0428MFCwindllView)

// ����
public:
	CMy0428MFCwindllDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy0428MFCwindllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 0428MFCwindllView.cpp �еĵ��԰汾
inline CMy0428MFCwindllDoc* CMy0428MFCwindllView::GetDocument() const
   { return reinterpret_cast<CMy0428MFCwindllDoc*>(m_pDocument); }
#endif


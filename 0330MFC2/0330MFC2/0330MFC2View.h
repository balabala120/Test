
// 0330MFC2View.h : CMy0330MFC2View ��Ľӿ�
//

#pragma once


class CMy0330MFC2View : public CView
{
protected: // �������л�����
	CMy0330MFC2View();
	DECLARE_DYNCREATE(CMy0330MFC2View)

// ����
public:
	CMy0330MFC2Doc* GetDocument() const;
	int flag;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy0330MFC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // 0330MFC2View.cpp �еĵ��԰汾
inline CMy0330MFC2Doc* CMy0330MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0330MFC2Doc*>(m_pDocument); }
#endif



// 0427MFC2Doc.h : CMy0427MFC2Doc ��Ľӿ�
//


#pragma once


class CMy0427MFC2Doc : public CDocument
{
protected: // �������л�����
	CMy0427MFC2Doc();
	DECLARE_DYNCREATE(CMy0427MFC2Doc)

// ����
public:
	CArray<CRect,CRect&>ca;
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMy0427MFC2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};

// FakeWineLib.h : CFakeWineLib ������

#pragma once

// ���������� 2014��6��6��, 16:31

class CFakeWineLib : public CRecordset
{
public:
	CFakeWineLib(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CFakeWineLib)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	CStringW	m_SpectrumID;
	CStringW	m_SpectrumData;
	CStringW	m_WineNameFaked;
	CStringW	m_Comfrom;
	CStringW	m_ImportDate;
	CStringW	m_Manager;
	CStringW	m_WaveNumber;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


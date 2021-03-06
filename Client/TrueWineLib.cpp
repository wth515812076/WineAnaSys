// TrueWineLib.h : CTrueWineLib 类的实现



// CTrueWineLib 实现

// 代码生成在 2014年6月6日, 15:17

#include "stdafx.h"
#include "TrueWineLib.h"
IMPLEMENT_DYNAMIC(CTrueWineLib, CRecordset)

CTrueWineLib::CTrueWineLib(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_WineName = L"";
	m_AlcoholContent = L"";
	m_Flavour = L"";
	m_Brand = L"";
	m_ProductionBatchNo = L"";
	m_ProductionDate = L"";
	m_SpectrumData = L"";
	m_ComFrom = L"";
	m_ImportDate = L"";
	m_SpecID = L"";
	m_Manager = L"";
	m_WaveNumber = L"";
	m_nFields = 12;
	m_nDefaultType = dynaset;
}
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CTrueWineLib::GetDefaultConnect()
{
	return _T("DSN=\x767d\x9152\x9274\x5b9a\x4e0e\x6eaf\x6e90\x6570\x636e\x5e93;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae 2010;WSID=WTH515812076-PC;DATABASE=\x767d\x9152\x9274\x5b9a\x4e0e\x6eaf\x6e90\x6570\x636e\x5e93");
}

CString CTrueWineLib::GetDefaultSQL()
{
	return _T("[dbo].[TrueWineLib]");
}

void CTrueWineLib::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[WineName]"), m_WineName);
	RFX_Text(pFX, _T("[AlcoholContent]"), m_AlcoholContent);
	RFX_Text(pFX, _T("[Flavour]"), m_Flavour);
	RFX_Text(pFX, _T("[Brand]"), m_Brand);
	RFX_Text(pFX, _T("[ProductionBatchNo]"), m_ProductionBatchNo);
	RFX_Text(pFX, _T("[ProductionDate]"), m_ProductionDate);
	RFX_Text(pFX, _T("[SpectrumData]"), m_SpectrumData,20000);
	RFX_Text(pFX, _T("[ComFrom]"), m_ComFrom);
	RFX_Text(pFX, _T("[ImportDate]"), m_ImportDate);
	RFX_Text(pFX, _T("[SpecID]"), m_SpecID);
	RFX_Text(pFX, _T("[Manager]"), m_Manager);
	RFX_Text(pFX, _T("[WaveNumber]"), m_WaveNumber,20000);

}
/////////////////////////////////////////////////////////////////////////////
// CTrueWineLib 诊断

#ifdef _DEBUG
void CTrueWineLib::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTrueWineLib::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG



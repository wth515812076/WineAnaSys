// SelectSpecFromLibDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Client.h"
#include "SelectSpecFromLibDlg.h"
#include "afxdialogex.h"

// CSelectSpecFromLibDlg �Ի���

IMPLEMENT_DYNAMIC(CSelectSpecFromLibDlg, CDialogEx)

CSelectSpecFromLibDlg::CSelectSpecFromLibDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelectSpecFromLibDlg::IDD, pParent)
	, m_Key1(_T(""))
	, m_Key2(_T(""))
	, m_Key3(_T(""))
{
	//m_pTrueWineLib=new CTrueWineLib();

	m_TrueWineLib.m_strSort=L"WineName";
}

CSelectSpecFromLibDlg::~CSelectSpecFromLibDlg()
{
}

void CSelectSpecFromLibDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_FIELD1, m_ComboField1);
	DDX_Control(pDX, IDC_COMBO_FIELD2, m_ComboField2);
	DDX_Control(pDX, IDC_COMBO_FIELD3, m_ComboField3);
	DDX_Control(pDX, IDC_COMBO_ANDOR1, m_ComboAndOr1);
	DDX_Control(pDX, IDC_COMBO_ANDOR2, m_ComboAndOr2);
	DDX_Text(pDX, IDC_EDIT_KEY1, m_Key1);
	DDX_Text(pDX, IDC_EDIT_KEY2, m_Key2);
	DDX_Control(pDX, IDC_EDIT_KEY3, m_key3);
	DDX_Control(pDX, IDC_LIST_SPECLIB, m_ListSpec);
	DDX_Text(pDX, IDC_EDIT_KEY3, m_Key3);
}


BEGIN_MESSAGE_MAP(CSelectSpecFromLibDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEARCHWITHKEYWORDS, &CSelectSpecFromLibDlg::OnBnClickedButtonSearchwithkeywords)
	ON_BN_CLICKED(IDC_BUTTON_SHOWALL, &CSelectSpecFromLibDlg::OnBnClickedButtonShowall)
	ON_BN_CLICKED(IDOK, &CSelectSpecFromLibDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSelectSpecFromLibDlg ��Ϣ��������




BOOL CSelectSpecFromLibDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ����Ӷ���ĳ�ʼ��
	m_ComboField1.InsertString(0,L"������");
	m_ComboField1.InsertString(1,L"�׾�����");
	m_ComboField1.InsertString(2,L"�׾ƾƾ�����");
	m_ComboField1.InsertString(3,L"�׾�����");
	m_ComboField1.InsertString(4,L"�׾�Ʒ��");

	m_ComboField2.InsertString(0,L"������");
	m_ComboField2.InsertString(1,L"�׾�����");
	m_ComboField2.InsertString(2,L"�׾ƾƾ�����");
	m_ComboField2.InsertString(3,L"�׾�����");
	m_ComboField2.InsertString(4,L"�׾�Ʒ��");

	m_ComboField3.InsertString(0,L"������");
	m_ComboField3.InsertString(1,L"�׾�����");
	m_ComboField3.InsertString(2,L"�׾ƾƾ�����");
	m_ComboField3.InsertString(3,L"�׾�����");
	m_ComboField3.InsertString(4,L"�׾�Ʒ��");

	m_ComboField1.SetCurSel(0);
	m_ComboField2.SetCurSel(0);
	m_ComboField3.SetCurSel(0);

	m_ComboAndOr1.InsertString(0,L"AND");
	m_ComboAndOr1.InsertString(1,L"OR");
	m_ComboAndOr2.InsertString(0,L"AND");
	m_ComboAndOr2.InsertString(1,L"OR");

	m_ComboAndOr1.SetCurSel(0);
	m_ComboAndOr2.SetCurSel(0);
	///////////////////
	DWORD dwStyle;

	m_ListSpec.InsertColumn( 0, L"�������", LVCFMT_LEFT, 100 );//������
	m_ListSpec.InsertColumn( 1, L"�׾�����", LVCFMT_LEFT, 100 );//������ 
	m_ListSpec.InsertColumn( 2, L"�׾���Ϣ", LVCFMT_LEFT, 150 );//������ 
	m_ListSpec.InsertColumn( 2, L"��������", LVCFMT_LEFT, 100 );//������
	m_ListSpec.InsertColumn( 3, L"��������", LVCFMT_LEFT, 100 );//������
	m_ListSpec.InsertColumn( 4, L"��Դ˵��", LVCFMT_LEFT, 100 );//������
	m_ListSpec.InsertColumn( 5, L"�������", LVCFMT_LEFT, 100 );//������

	dwStyle = m_ListSpec.GetExtendedStyle(); //��ȡ��ǰ��չ��ʽ
	dwStyle |= LVS_EX_FULLROWSELECT; //ѡ��ĳ��ʹ���и�����report���ʱ��
	dwStyle |= LVS_EX_GRIDLINES; //�����ߣ�report���ʱ��
	//  dwStyle |= LVS_EX_CHECKBOXES; //itemǰ����checkbox�ؼ�
	m_ListSpec.SetExtendedStyle(dwStyle); 

    ////


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CSelectSpecFromLibDlg::OnBnClickedButtonSearchwithkeywords()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(TRUE);
	if(!m_TrueWineLib.IsOpen())
	{
		m_TrueWineLib.Open();
	}

	if(m_Key1.IsEmpty()&&m_Key2.IsEmpty()&&m_Key3.IsEmpty())
	{
		MessageBox(L"����д�����ؼ��ʣ�",L"��������",MB_ICONWARNING);
		m_TrueWineLib.Close();
		return ;
	}

	CString strFilter1,strFilter2,strFilter3;
	CString AndOr1,AndOr2;

	m_ComboAndOr1.GetLBText(m_ComboField1.GetCurSel(),AndOr1);
	m_ComboAndOr2.GetLBText(m_ComboField2.GetCurSel(),AndOr2);

	m_TrueWineLib.m_strFilter=L"";

	if(!m_Key1.IsEmpty())
	{
		CString ComboField1;

		m_ComboField1.GetLBText(m_ComboField1.GetCurSel(),ComboField1);
		if(ComboField1 == L"������")
		{
			strFilter1.Format(L" (WineName = '%s' OR AlcoholContent = '%s' OR Flavour = '%s' OR Brand = '%s') ",
				m_Key1,m_Key1,m_Key1,m_Key1);
		}
		else if(ComboField1 == L"�׾�����")
		{
			strFilter1.Format(L" (WineName = '%s') ",m_Key1);
		}
		else if(ComboField1 == L"�׾ƾƾ�����")
		{
			strFilter1.Format(L" (AlcoholContent = '%s') ",m_Key1);
		}
		else if(ComboField1 == L"�׾�����")
		{
			strFilter1.Format(L" (Flavour = '%s') ",m_Key1);
		}
		else if(ComboField1 == L"�׾�Ʒ��")
		{
			strFilter1.Format(L" (Brand = '%s') ",m_Key1);
		}
		m_TrueWineLib.m_strFilter+=strFilter1;
	}

	if(!m_Key2.IsEmpty())
	{
		CString ComboField2;
		m_ComboField2.GetLBText(m_ComboField2.GetCurSel(),ComboField2);

		if(ComboField2 == L"������")
		{

			strFilter2.Format(L" (WineName = '%s' OR AlcoholContent = '%s' OR Flavour = '%s' OR Brand = '%s') ",
				m_Key2,m_Key2,m_Key2,m_Key2);
		}
		else if(ComboField2 == L"�׾�����")
		{
			strFilter2.Format(L" (WineName = '%s') ",m_Key2);
		}
		else if(ComboField2 == L"�׾ƾƾ�����")
		{
			strFilter2.Format(L" (AlcoholContent = '%s') ",m_Key2);
		}
		else if(ComboField2 == L"�׾�����")
		{
			strFilter2.Format(L" (Flavour = '%s')",m_Key2);
		}
		else if(ComboField2 == L"�׾�Ʒ��")
		{
			strFilter2.Format(L" (Brand = '%s') ",m_Key2);
		}
		if(!m_TrueWineLib.m_strFilter.IsEmpty())
			m_TrueWineLib.m_strFilter+=AndOr1;
		m_TrueWineLib.m_strFilter+=strFilter2;
	}
	///////
	if(!m_Key3.IsEmpty())
	{

		CString ComboField3;
		m_ComboField3.GetLBText(m_ComboField3.GetCurSel(),ComboField3);	
		if(ComboField3 == L"������")
		{

			strFilter3.Format(L" (WineName = '%s' OR AlcoholContent = '%s' OR Flavour = '%s' OR Brand = '%s') ",
				m_Key3,m_Key3,m_Key3,m_Key3);
		}
		else if(ComboField3 == L"�׾�����")
		{
			strFilter3.Format(L" (WineName = '%s') ",m_Key3);
		}
		else if(ComboField3 == L"�׾ƾƾ�����")
		{
			strFilter3.Format(L" (AlcoholContent = '%s') ",m_Key3);
		}
		else if(ComboField3 == L"�׾�����")
		{
			strFilter3.Format(L" (Flavour = '%s') ",m_Key3);
		}
		else if(ComboField3 == L"�׾�Ʒ��")
		{
			strFilter3.Format(L" (Brand = '%s') ",m_Key3);
		}
		if(!m_TrueWineLib.m_strFilter.IsEmpty())
			m_TrueWineLib.m_strFilter+=AndOr2;
		m_TrueWineLib.m_strFilter+=strFilter3;
	}

	m_TrueWineLib.Requery();
	ShowSpec();
}


void CSelectSpecFromLibDlg::OnBnClickedButtonShowall()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	if(!m_TrueWineLib.IsOpen())
	{
		m_TrueWineLib.Open();
	}
	else
	{
		m_TrueWineLib.m_strFilter=L"";
		m_TrueWineLib.Requery();
	}
	ShowSpec();
}


int CSelectSpecFromLibDlg::ShowSpec(void)
{
	m_ListSpec.DeleteAllItems();
	if(m_TrueWineLib.IsEOF())
	{
		MessageBox(L"û����ؼ�¼!",L"�޼�¼",MB_ICONWARNING);
		return -1;
	}
	m_TrueWineLib.MoveFirst();

	int count=0;
	while(!m_TrueWineLib.IsEOF())
	{
		CString temp;
		temp.Format(L"%s,%s,%s",m_TrueWineLib.m_AlcoholContent,m_TrueWineLib.m_Flavour,m_TrueWineLib.m_Brand);
		m_ListSpec.InsertItem(count,m_TrueWineLib.m_WineName);
		m_ListSpec.SetItemText(count,1,temp);
		m_ListSpec.SetItemText(count,2,m_TrueWineLib.m_ProductionDate);
		m_ListSpec.SetItemText(count,3,m_TrueWineLib.m_ProductionBatchNo);
		m_ListSpec.SetItemText(count,4,m_TrueWineLib.m_ComFrom);
		m_ListSpec.SetItemText(count,5,m_TrueWineLib.m_ImportDate);


		m_TrueWineLib.MoveNext();
		count++;
	}
	m_TrueWineLib.MoveFirst();
	return 0;
}


void CSelectSpecFromLibDlg::OnBnClickedOk()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	CDialogEx::OnOK();
}
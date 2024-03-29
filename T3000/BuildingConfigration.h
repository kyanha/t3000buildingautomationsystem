#pragma once

#include "CM5/ListCtrlEx.h"
#include "afxcmn.h"
#include "globle_function.h"
#include "afxwin.h"
// CBuildingConfigration dialog

typedef struct Building_Config 
{
	bool b_selected;
	int ID;
	CString MainBuildingName;
	CString Sub_NetName;
	CString country;
	CString state;
	CString city;
	CString street;
	    int Zip;
	CString Protocol;
	CString IPAddress_Domain;
	CString IP_Port;
	CString Comport;
	CString BaudRate;
	unsigned int protocol_index;
	CString BuildingPath;

	CString Longitude;
	CString Latitude ;
	CString Elevation;
	CString EngineeringUnits;
};

class CBuildingConfigration : public CDialogEx
{
	DECLARE_DYNAMIC(CBuildingConfigration)

public:
	CBuildingConfigration(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBuildingConfigration();

// Dialog Data
	enum { IDD = IDD_BUILDING_CONFIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void Initial_Building_List();
	void Fresh_List_Row();
	void LoadBuildingConfigDB();
	afx_msg LRESULT Fresh_Building_Config_Item(WPARAM wParam,LPARAM lParam);
	ListCtrlEx::CListCtrlEx m_building_config_list;
	_ConnectionPtr m_building_pCon;
	_RecordsetPtr m_building_pRs;
	vector<Building_Config> m_BuildNameLst;
	vector<CString>				m_szBuildingComs;
	afx_msg void OnBnClickedBuildingButtonAdd();
	afx_msg void OnBnClickedBuildingButtonDelete();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CButton m_addBuildingButton;
	CButton m_deleteBuildingButton;
	afx_msg void OnNMClickListBuildingConfig(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickListBuildingConfig(NMHDR *pNMHDR, LRESULT *pResult);
	vector<CString> m_vecdbfile;
	afx_msg void OnBuildingconfigSelect();
	afx_msg void OnBuildingconfigUnselect();
	afx_msg void OnBuildingconfigDelete();
	void Update_Building();
    void Deal_BuildingPath();
	int m_curRow;
	int m_curCol;
	int m_changedRow;
	int m_changedCol;
	BOOL m_bChanged;
	CString m_select_text;
	char m_sqlitepath[256];
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedOk();
	afx_msg void OnNMDblclkListBuildingConfig(NMHDR *pNMHDR, LRESULT *pResult);
};

const int BC_ITEM = 0;
const int BC_MAINNAME = 1;
//const int BC_SUBNAME = 2;
const int BC_PROTOCOL = 2;
const int BC_IPADDRESS = 3;
const int BC_IPPORT = 4;
const int BC_COMPORT = 5;
const int BC_BAUDRATE = 6;
const int BC_BUILDINGPATH = 7;

const int BC_COL_NUMBER = 8;





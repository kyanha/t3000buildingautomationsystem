#include "StdAfx.h"
#include "T3000RegAddress.h"

#include "T3000.h"
#include "MainFrm.h"
#include "afxwin.h"


wchar_t m_ini_path_t3000[255];
wchar_t m_mdb_path_t3000[255];
int Mdb_Adress_Map=0;
int temp_Mdb_Adress_Map=0;
struct AddressMap 
{
	wchar_t AddressName[255];
	int AddressValue;
};

AddressMap TSTAT_6_ADDRESS[1000];
AddressMap TSTAT_5EH_LCD_ADDRESS[1000];
AddressMap TSTAT_5ABCDFG_LED_ADDRESS[1000];

T3000RegAddress::T3000RegAddress(void)
{
	memset(m_ini_path_t3000,0,sizeof(m_ini_path_t3000));

	//MODBUS_TEMPRATURE_CHIP.AddressName ="MODBUS_TEMPRATURE_CHIP";
}


T3000RegAddress::~T3000RegAddress(void)
{
}


int _Get(wchar_t *str,int mMdb_Adress_Map)
{
	if(mMdb_Adress_Map==T3000_5ABCDFG_LED_ADDRESS)
	{
		for (int i=0;i<sizeof(TSTAT_5ABCDFG_LED_ADDRESS)/sizeof(TSTAT_5ABCDFG_LED_ADDRESS[0]);i++)
		{
			if(_tcscmp(TSTAT_5ABCDFG_LED_ADDRESS[i].AddressName,str)==0)
			{
				return TSTAT_5ABCDFG_LED_ADDRESS[i].AddressValue;
			}
		}
	}
	else if(mMdb_Adress_Map==T3000_5EH_LCD_ADDRESS)
	{
		for (int i=0;i<sizeof(TSTAT_5EH_LCD_ADDRESS)/sizeof(TSTAT_5EH_LCD_ADDRESS[0]);i++)
		{
			if(_tcscmp(TSTAT_5EH_LCD_ADDRESS[i].AddressName,str)==0)
			{
				return TSTAT_5EH_LCD_ADDRESS[i].AddressValue;
			}
		}
	}
	else if(mMdb_Adress_Map==T3000_6_ADDRESS)
	{
		for (int i=0;i<sizeof(TSTAT_6_ADDRESS)/sizeof(TSTAT_6_ADDRESS[0]);i++)
		{
			if(_tcscmp(TSTAT_6_ADDRESS[i].AddressName,str)==0)
			{
				return TSTAT_6_ADDRESS[i].AddressValue;
			}
		}
	}

	return -1;
}


bool T3000RegAddress::MatchMoudleAddress(void)
{
	_tcscpy_s(m_mdb_path_t3000,sizeof(m_mdb_path_t3000),_T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source="));
	GetModuleFileName(NULL, m_ini_path_t3000, MAX_PATH); 
	PathRemoveFileSpec(m_ini_path_t3000);

	_tcscat_s(m_mdb_path_t3000,sizeof(m_ini_path_t3000),m_ini_path_t3000);

	//_tcscat(m_mdb_path,_T("\\try.mdb"));
	_tcscat(m_mdb_path_t3000,_T("\\Database\\t3000.mdb"));
	//_tcscat(m_ini_path_t3000,_T("\\AddressConfig.ini"));


	//	 MODBUS_TEMPRATURE_CHIP=GetPrivateProfileInt(_T("Setting"),_T("MODBUS_TEMPRATURE_CHIP"),111,m_ini_path);

	HRESULT hr;
	m_pCon.CreateInstance(_T("ADODB.Connection"));
	hr=m_pRs.CreateInstance(_T("ADODB.Recordset"));
	if(FAILED(hr))
	{
		AfxMessageBox(_T("Load msado12.dll erro"));
		return FALSE;
	}
	m_pCon->Open(m_mdb_path_t3000,_T(""),_T(""),adModeUnknown);
	_variant_t temp_variant_item;
	_variant_t temp_variant;
	_variant_t temp_variant_value;
	CString strSql;

	strSql.Format(_T("select * from T3000_Register_Address_By_Name order by nItem"));
	m_pRs->Open((_variant_t)strSql,_variant_t((IDispatch *)m_pCon,true),adOpenStatic,adLockOptimistic,adCmdText);	
	while(VARIANT_FALSE==m_pRs->EndOfFile)
	{
		temp_variant_item = m_pRs->GetCollect(_T("nItem"));
	
			temp_variant=m_pRs->GetCollect(_T("Register_Name"));
			CString cs_temp=temp_variant;
			cs_temp = cs_temp.Trim();
			_tcscpy_s(TSTAT_5ABCDFG_LED_ADDRESS[temp_variant_item].AddressName,MAX_PATH,cs_temp);
			_tcscpy_s(TSTAT_5EH_LCD_ADDRESS[temp_variant_item].AddressName,MAX_PATH,cs_temp);
			_tcscpy_s(TSTAT_6_ADDRESS[temp_variant_item].AddressName,MAX_PATH,cs_temp);

			temp_variant_value=m_pRs->GetCollect(_T("TSTAT_6_7_Address"));
			TSTAT_6_ADDRESS[temp_variant_item].AddressValue = temp_variant_value;
			temp_variant_value=m_pRs->GetCollect(_T("TSTAT5_ABCDFG_Address"));
			TSTAT_5ABCDFG_LED_ADDRESS[temp_variant_item].AddressValue = temp_variant_value;
			temp_variant_value=m_pRs->GetCollect(_T("TSTAT5_EH_Address"));
			TSTAT_5EH_LCD_ADDRESS[temp_variant_item].AddressValue = temp_variant_value;
		m_pRs->MoveNext();
	}
	if(m_pRs->State)
		m_pRs->Close(); 
	//strSql.Format(_T("select * from T3000_5ABCDFG_LED_ADDRESS order by mItem"));
	//m_pRs->Open((_variant_t)strSql,_variant_t((IDispatch *)m_pCon,true),adOpenStatic,adLockOptimistic,adCmdText);	
	//while(VARIANT_FALSE==m_pRs->EndOfFile)
	//{
	//	temp_variant_item = m_pRs->GetCollect(_T("mItem"));
	//	temp_variant=m_pRs->GetCollect(_T("AddressName"));
	//	CString cs_temp=temp_variant;
	//	cs_temp = cs_temp.Trim();
	//	_tcscpy_s(TSTAT_5ABCDFG_LED_ADDRESS[temp_variant_item].AddressName,MAX_PATH,cs_temp);//	 = cs_temp;
	//	temp_variant_value=m_pRs->GetCollect(_T("Address"));
	//	TSTAT_5ABCDFG_LED_ADDRESS[temp_variant_item].AddressValue = temp_variant_value;
	//	m_pRs->MoveNext();
	//}
	//if(m_pRs->State)
	//	m_pRs->Close(); 
	//strSql.Format(_T("select * from T3000_5EH_LCD_ADDRESS order by mItem"));
	//m_pRs->Open((_variant_t)strSql,_variant_t((IDispatch *)m_pCon,true),adOpenStatic,adLockOptimistic,adCmdText);	
	//while(VARIANT_FALSE==m_pRs->EndOfFile)
	//{
	//	temp_variant_item = m_pRs->GetCollect(_T("mItem"));
	//	temp_variant=m_pRs->GetCollect(_T("AddressName"));
	//	CString cs_temp=temp_variant;
	//	cs_temp = cs_temp.Trim();
	//	_tcscpy_s(TSTAT_5EH_LCD_ADDRESS[temp_variant_item].AddressName,MAX_PATH,cs_temp);//	 = cs_temp;
	//	temp_variant_value=m_pRs->GetCollect(_T("Address"));
	//	TSTAT_5EH_LCD_ADDRESS[temp_variant_item].AddressValue = temp_variant_value;
	//	m_pRs->MoveNext();
	//}


	//if(m_pRs->State)
	//	m_pRs->Close(); 
	if(m_pCon->State)
		m_pCon->Close();

	return true;
}


 float my_get_tstat_version(unsigned short tstat_id)
 {//get tstat version and judge the tstat is online or no
	 //tstat is online ,return >0
	 //tstat is not online ,return -2

	 float tstat_version2=(float)read_one((unsigned char)tstat_id,4);//tstat version			
	 if(tstat_version2==-2 || tstat_version2==-3)
		 return tstat_version2;
	 if(tstat_version2 >=240 && tstat_version2 <250)
		 tstat_version2 /=10;
	 else 
	 {
		 tstat_version2 = (float)(read_one((unsigned char)tstat_id,5,1)*256+read_one((unsigned char)tstat_id,4,1));	
		 tstat_version2 /=10;
	 }//tstat_version
	 return tstat_version2;
 }

 float my_get_curtstat_version()
 {
	 float tstat_version2=multi_register_value[MODBUS_VERSION_NUMBER_LO];//tstat version			
	 if(tstat_version2<=0)
		 return tstat_version2;
	 if(tstat_version2 >=240 && tstat_version2 <250)
		 tstat_version2 /=10;
	 else 
	 {
		 tstat_version2 = (float)(multi_register_value[MODBUS_VERSION_NUMBER_HI]*256+multi_register_value[MODBUS_VERSION_NUMBER_LO]);	
		 tstat_version2 /=10;
	 }//tstat_version
	 return tstat_version2;

 }


 bool my_get_serialnumber(long & serial,int the_id_of_product)
 {
	 unsigned short SerialNum[4]={0};
	 int nRet=0;
	 nRet=Read_Multi(the_id_of_product,&SerialNum[0],0,4);
	 serial=0;
	 if(nRet>0)
	 {
		 serial=SerialNum[0]+SerialNum[1]*256+SerialNum[2]*256*256+SerialNum[3]*256*256*256;
		 return TRUE;
	 }
	 return FALSE;
 }

 UINT my_get_serialnumber()
 {
	 return multi_register_value[_Get(_T("MODBUS_SERIALNUMBER_LOWORD"))]
	+multi_register_value[_Get(_T("MODBUS_SERIALNUMBER_LOWORD"))+1]*256
	+multi_register_value[_Get(_T("MODBUS_SERIALNUMBER_HIWORD"))]*256*256
	+multi_register_value[_Get(_T("MODBUS_SERIALNUMBER_HIWORD"))+1]*256*256*256;
 }


 void Savetmp_Mdb_Adress_Map()
 {
	 temp_Mdb_Adress_Map =Mdb_Adress_Map;
 }

 void Set_Mdb_Adress_Map(int myMdb_Adress_Map)
 {
	Mdb_Adress_Map= myMdb_Adress_Map;
 }

 void Restore_Mdb_Adress_Map()
 {
	Mdb_Adress_Map= temp_Mdb_Adress_Map ;
 }


 BOOL DelDirW(CString strSrcPath)
 { 
	 if(!PathIsDirectory(strSrcPath))//源目录是否存在 
		 return false;
	 CFileFind finder;
	 // 打开指定的文件夹进行搜索
	 BOOL bWorking = (BOOL)finder.FindFile(strSrcPath + _T("\\") + _T("*.*")); 
	 while(bWorking)
	 {
		 // 从当前目录搜索文件
		 bWorking = finder.FindNextFile();
		 CString strFileName = finder.GetFileName();
		 CString strSrc = strSrcPath + _T("\\") + strFileName;

		 // 判断搜索到的是不是"."和".."目录
		 if(!finder.IsDots())
		 {// 判断搜索到的目录是否是文件夹
			 if(finder.IsDirectory())
			 { // 如果是文件夹的话，进行递归
				 DelDirW(strSrc);
			 }
			 else
			 {// 如果是文件，直接删除
				 DeleteFileW(strSrc);
			 }
		 }
	 }
	 finder.Close();
	 return RemoveDirectory(strSrcPath);
 }	
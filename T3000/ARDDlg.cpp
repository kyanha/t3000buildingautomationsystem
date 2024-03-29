// ARDDlg.cpp : implementation file
//

#include "stdafx.h"
#include "T3000.h"
#include "ARDDlg.h"
#include "afxdialogex.h"
#include "ado/ADO.h"

// CARDDlg dialog

IMPLEMENT_DYNAMIC(CARDDlg, CDialogEx)

CARDDlg::CARDDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CARDDlg::IDD, pParent)
    , m_Serial_Number(0)
    , m_type_id(_T(""))
{

}

BOOL CARDDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	GetSerialComPortNumber1(m_szComm);
	for (UINT i = 0; i < m_szComm.size(); i++)
	{
		m_add_device_com_port.AddString(m_szComm[i]);
	}
	m_add_device_com_port.SetCurSel(0);

	m_add_device_baudrate.InsertString(0,_T("9600"));
	m_add_device_baudrate.InsertString(1,_T("19200"));
	m_add_device_baudrate.InsertString(2,_T("38400"));
	m_add_device_baudrate.InsertString(3,_T("57600"));
	m_add_device_baudrate.InsertString(4,_T("115200"));
	m_add_device_baudrate.SetCurSel(1);
	m_add_device_modbus_id.SetWindowText(_T("255"));
	m_ipaddress.SetWindowText(_T("127.0.0.1"));
	m_porteditor.SetWindowText(_T("502"));
    m_minipanel_comport.SetCurSel(0);
	((CButton *)GetDlgItem(IDC_RADIO_NET_DEVICE))->SetCheck(TRUE);//选上
	Enable_Net_UI(true);
    OnCbnDropdownComboProductName();

	return TRUE; 
}

void CARDDlg::Enable_Net_UI(bool enable_net)
{
	m_is_net_device = enable_net;
	if(enable_net)
	{
		m_ipaddress.EnableWindow(1);
		m_porteditor.EnableWindow(1);
        m_minipanel_comport.EnableWindow(1);
		m_add_device_com_port.EnableWindow(0);
		m_add_device_baudrate.EnableWindow(0);
		//m_add_device_modbus_id.EnableWindow(0);
	}
	else
	{
		m_ipaddress.EnableWindow(0);
		m_porteditor.EnableWindow(0);
        m_minipanel_comport.EnableWindow(0);
		m_add_device_com_port.EnableWindow(1);
		m_add_device_baudrate.EnableWindow(1);
		//m_add_device_modbus_id.EnableWindow(1);
	}
}

CARDDlg::~CARDDlg()
{
}

void CARDDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_IPADDRESS1, m_ipaddress);
    DDX_Control(pDX, IDC_PORT, m_porteditor);
    DDX_Control(pDX, IDC_COMBO_ADD_DEVICE_COMPORT, m_add_device_com_port);
    DDX_Control(pDX, IDC_COMBO_ADD_DEVICE_BAUDRATE, m_add_device_baudrate);
    DDX_Control(pDX, IDC_EDIT_ADD_DEVICE_MODBUS_ID, m_add_device_modbus_id);
    DDX_Text(pDX, IDC_EDIT_SERIAL_NUMBER, m_Serial_Number);
    DDX_Text(pDX, IDC_EDIT_TYPE_ID, m_type_id);
    DDX_Control(pDX, IDC_COMBO_PRODUCT_NAME, m_combox_productname);
    DDX_Control(pDX, IDC_COMBO1, m_minipanel_comport);
}


BEGIN_MESSAGE_MAP(CARDDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CARDDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO_NET_DEVICE, &CARDDlg::OnBnClickedRadioNetDevice)
	ON_BN_CLICKED(IDC_RADIO2, &CARDDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON_LOCAL_MSTP_DEVICE, &CARDDlg::OnBnClickedButtonLocalMstpDevice)
    ON_CBN_DROPDOWN(IDC_COMBO_PRODUCT_NAME, &CARDDlg::OnCbnDropdownComboProductName)
    ON_CBN_SELCHANGE(IDC_COMBO_PRODUCT_NAME, &CARDDlg::OnCbnSelchangeComboProductName)
    ON_EN_KILLFOCUS(IDC_EDIT_TYPE_ID, &CARDDlg::OnEnKillfocusEditTypeId)
//    ON_EN_KILLFOCUS(IDC_EDIT_ADD_DEVICE_MODBUS_ID, &CARDDlg::OnEnKillfocusEditAddDeviceModbusId)
END_MESSAGE_MAP()


// CARDDlg message handlers


void CARDDlg::OnBnClickedOk()
{
    
   CString ip;
   CString strport;
   BOOL is_open = false;   
   int temp_communication_type = GetLastCommunicationType();
   int temp_comport = 0;
   int temp_baudrate = 19200;
   int read_modbus_id = 255;
   CString temp_cs_port;
   CString temp_baud;
   CString temp_id;
   CString StrProtocol;
   int nComport = 0;
   UpdateData(TRUE);
   int product_type_id = _wtoi(m_type_id);
   if (product_type_id < 220 && product_type_id != 210)
   {
       AfxMessageBox(_T(" In order to identify your product,Please Enter a number not less than 220!")) ;
       return;
   }
   m_add_device_modbus_id.GetWindowTextW(temp_id);
   read_modbus_id = _wtoi(temp_id); 
   if (read_modbus_id <0||read_modbus_id>254)
   {
       AfxMessageBox(_T("Modbus ID should be more than 1 and less than 255")) ;
       return;
   }
   

   if(temp_communication_type == 0)
   {
	   temp_comport = GetLastOpenedComport();
	   temp_baudrate = GetLastSuccessBaudrate();
   }

   if(m_is_net_device)
   {
	   m_ipaddress.GetWindowText(ip);
	   m_porteditor.GetWindowText(strport);
	   if (ip.IsEmpty()||strport.IsEmpty())
	   {
		   AfxMessageBox(_T("ip or port can not be empty!"));
		   return;
	   }
	   short port=_wtoi(strport);
	   SetCommunicationType(1);
	   is_open=Open_Socket2(ip,port);
       StrProtocol=_T("1");
   }
   else
   {
	   SetCommunicationType(0);
	   close_com();

	   m_add_device_com_port.GetWindowTextW(temp_cs_port);
	   m_add_device_baudrate.GetWindowTextW(temp_baud);
	   
	    nComport = _wtoi(temp_cs_port.Mid(3));
		int nbaudrate = _wtoi(temp_baud);
		

// 		if((nbaudrate != 19200) && (nbaudrate != 9600))
// 		{
// 			is_open = false;
// 		}
// 		else
// 		{
			if(nComport > 0)
			{
				BOOL  bret = open_com(nComport);
				Change_BaudRate(nbaudrate);
				if(bret)
					is_open = true;
				else
					is_open = false;
			}
			else
			{
				is_open = false;
			}
		/*}*/
          StrProtocol=_T("0");


   }


   

   if (is_open)
   {
	   CString strSql;
	   CString strMainBuildName,strSubBuildingName,strSID,strFloorName,strRoomName,strProID;
	   CString strProName,strProType,strScreenID,strBaudrate,strGraphicID,strHdVersion,strStVersion,strCom,strEPSize;
       CString Product_Name;
       CString strCustomer;
       
       int ParnetModbusID=0;
      
       m_combox_productname.GetWindowText(Product_Name); 

	   CMainFrame* pFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
	   strMainBuildName= pFrame->m_strCurMainBuildingName;
	   strSubBuildingName= pFrame->m_strCurSubBuldingName;
	   int SN=m_Serial_Number;
       strSID.Format(_T("%d"),SN);
	   strFloorName=_T("floor1");
	   strRoomName=_T("room1");
	   strProName.Format(_T("%s:%d--%d"),Product_Name,SN,read_modbus_id);
	   strProType.Format(_T("%d"),product_type_id);
	   strProID.Format(_T("%d"),read_modbus_id);

	   strScreenID.Format(_T("Screen(S:%d--%d)"),SN,read_modbus_id);
	   if(m_is_net_device)
		m_ipaddress.GetWindowText(strBaudrate);
	   else
		   strBaudrate = temp_baud;
	   strGraphicID=_T("Clicking here to add a image...");
	   strHdVersion=_T("0.0");
	   strStVersion=_T("0.0");
	   if(m_is_net_device)
		 m_porteditor.GetWindowText(strCom);
	   else
	   {
		   CString temp1;
		   temp1.Format(_T("%d"),nComport);
			strCom = temp1;
	   }
	   strEPSize=_T("0.0");
	   try
	   {
		   CBADO bado;
		   bado.SetDBPath(g_strCurBuildingDatabasefilePath);
		   bado.OnInitADOConn(); 
           strSql.Format(_T("Select * from ALL_NODE where Product_name='%s'"),strProName.GetBuffer());
           bado.m_pRecordset=bado.OpenRecordset(strSql);
           if (!bado.m_pRecordset->EndOfFile)//有表但是没有对应序列号的值
           {
            AfxMessageBox(_T("Already Exists!"));
            return;
            //ado.m_pRecordset->Close();
           }
           if (product_type_id == 210)
           {
                 strCustomer=_T("0");
           }
           else
           {
                strCustomer=_T("1");
           }
            CString strParentSerialNumber;
           if (GetCommunicationType()==1)
           {
               unsigned short DataBuffer[16];
                memset(DataBuffer,0xffff,16);
               Read_Multi(255,DataBuffer,0,16);
               int seialnumber = DataBuffer[0]+DataBuffer[1]*255+DataBuffer[2]*255*255+DataBuffer[3]*255*255*255;
               strParentSerialNumber.Format(_T("%d"),seialnumber);  
               ParnetModbusID = DataBuffer[6];
               if (DataBuffer[7]==PM_MINIPANEL||DataBuffer[7]==PM_CM5)
               {     memset(DataBuffer,0xffff,16);
                     int miniport = m_minipanel_comport.GetCurSel();
                     DataBuffer[0]= read_modbus_id;
                     DataBuffer[1]= product_type_id;
                     DataBuffer[2]= miniport;

                     unsigned int loword,hiword;
                     loword=m_Serial_Number & 0xffff;

                     DataBuffer[3]=loword&0xff;
                     DataBuffer[4]=(loword >> 8);

                     hiword=(m_Serial_Number >> 16) & 0xffff;

                     DataBuffer[5]=  hiword&0xff;
                     DataBuffer[6]=  (hiword >> 8);
                     Product_Name.Delete(16,Product_Name.GetLength());
                     char p[16];
                     memset(p,0xff,16);
                     
                     WideCharToMultiByte( CP_ACP, 0, Product_Name.GetBuffer(), -1, p, 16, NULL, NULL );
                     Product_Name.ReleaseBuffer();
                     
                     union temp_char{
                     char ch_temp[16];
                     unsigned short sh_temp[8];
                     };
                     temp_char char_To_short;
                     for (int i=0;i<8;i++)
                     {
                       char_To_short.sh_temp[i]=0;
                     }
                     /*  for (int i=0;i<16;i++)
                     {
                     char_To_short.ch_temp[i]=p[i];
                     }*/
                     char_To_short.ch_temp[0]=p[1];
                     char_To_short.ch_temp[1]=p[0];
                     char_To_short.ch_temp[2]=p[3];
                     char_To_short.ch_temp[3]=p[2];
                     char_To_short.ch_temp[4]=p[5];
                     char_To_short.ch_temp[5]=p[4];
                     char_To_short.ch_temp[6]=p[7];
                     char_To_short.ch_temp[7]=p[6];
                     char_To_short.ch_temp[8]=p[9];
                     char_To_short.ch_temp[9]=p[8];
                     char_To_short.ch_temp[10]=p[11];
                     char_To_short.ch_temp[11]=p[10];
                     char_To_short.ch_temp[12]=p[13];
                     char_To_short.ch_temp[13]=p[12];
                     char_To_short.ch_temp[14]=p[15];
                     char_To_short.ch_temp[15]=p[14];

                     for(int i=0;i<8;i++)
                     {
                         DataBuffer[7+i]=char_To_short.sh_temp[i]; 
                     }
                    
                  int ret=  Write_Multi_short(ParnetModbusID,DataBuffer,280,16,5); 
                   if (ret>0)
                  {
                        AfxMessageBox(_T("Add OK"));
                        return;
                  } 

               }
               
                
		          strSql.Format(_T("insert into ALL_NODE (MainBuilding_Name,Building_Name,Serial_ID,Floor_name,Room_name,Product_name,Product_class_ID,Product_ID,Screen_Name,Bautrate,Background_imgID,Hardware_Ver,Software_Ver,Com_Port,Protocol,Custom,Parent_SerialNum,EPsize) values('"
		        	   +pFrame->m_strCurMainBuildingName+"','"
		        	   +pFrame->m_strCurMainBuildingName +"','"
		        	   +strSID+"','"
		        	   +strFloorName+"','"
		        	   +strRoomName+"','"
		        	   +strProName+"','"
		        	   +strProType+"','"
		        	   +strProID+"','"
		        	   +strScreenID+"','"
		        	   +strBaudrate+"','"
		        	   +strGraphicID+"','"
		        	   +strHdVersion+"','"
		        	   +strStVersion+"','"
		        	   +strCom+"','"
                      +StrProtocol+"','"
                      +strCustomer+"','"
                      +strParentSerialNumber+"','"
		        	   +strEPSize+"')"));

               }
               else
               {
                   strSql.Format(_T("insert into ALL_NODE (MainBuilding_Name,Building_Name,Serial_ID,Floor_name,Room_name,Product_name,Product_class_ID,Product_ID,Screen_Name,Bautrate,Background_imgID,Hardware_Ver,Software_Ver,Com_Port,Protocol,Custom,EPsize) values('"
                       +pFrame->m_strCurMainBuildingName+"','"
                       +pFrame->m_strCurMainBuildingName +"','"
                       +strSID+"','"
                       +strFloorName+"','"
                       +strRoomName+"','"
                       +strProName+"','"
                       +strProType+"','"
                       +strProID+"','"
                       +strScreenID+"','"
                       +strBaudrate+"','"
                       +strGraphicID+"','"
                       +strHdVersion+"','"
                       +strStVersion+"','"
                       +strCom+"','"
                       +StrProtocol+"','"
                       +strCustomer+"','"
                       +strEPSize+"')"));
               }
		   bado.m_pRecordset=bado.OpenRecordset(strSql);
		   bado.CloseConn();
		   AfxMessageBox(_T("Add OK!"));
           CDialogEx::OnOK();
	   }
	   
	   catch (CException* e)
	   {
		   AfxMessageBox(_T("Add Fail!"));
	   }
	  
	   
   }
   else
   {
	   AfxMessageBox(_T("Can not Connect"));
   }

}


void CARDDlg::OnBnClickedRadioNetDevice()
{
	// TODO: Add your control notification handler code here
	Enable_Net_UI(1);
}


void CARDDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	Enable_Net_UI(0);
}


void CARDDlg::OnBnClickedButtonLocalMstpDevice()
{
	// TODO: Add your control notification handler code here
	CBADO bado;
	bado.SetDBPath(g_strCurBuildingDatabasefilePath);
	bado.OnInitADOConn(); 

	MessageBox(_T("Scan device may take a few minutes , Please wait!!"));
	vector<CString>				m_szComs;
	GetSerialComPortNumber1(m_szComs);
	int com_port_count =  m_szComs.size();
	for (int z=1;z<com_port_count;z++)
	{
		CString temp_cstring;
		temp_cstring = m_szComs.at(z).Right(m_szComs.at(z).GetLength() - 3);
		int com_port =  _wtoi(temp_cstring);
		Initial_bac(com_port);




		for (int x=0;x<25;x++)
		{
			//CString strInfo;strInfo.Format(_T("Scan Com%d,protocol Bacnet MSTP.Send global command time left(%d)"),temp_port,14-i);
			//pScan->ShowBacnetComScanInfo(strInfo);
			Send_WhoIs_Global(-1,-1);
			Sleep(1000);
		}




		for (int j=0;j<5;j++)
		{
			int ready_to_read_count =	m_bac_scan_com_data.size();

			CString strInfo;
			strInfo.Format(_T("Scan  Bacnet mstp.Found %d BACNET device"),ready_to_read_count);
			if((int)m_bac_scan_result_data.size()>= ready_to_read_count)
				break;
			TRACE(_T("gloab scan = %d\r\n"),ready_to_read_count);
			for (int i=0;i<ready_to_read_count;i++)
			{
				int	resend_count = 0;
				do 
				{
					resend_count ++;
					if(resend_count>50)
						break;
					g_invoke_id = GetPrivateData(
						m_bac_scan_com_data.at(i).device_id,
						GETSERIALNUMBERINFO,
						0,
						0,
						sizeof(Str_Serial_info));		

					Sleep(SEND_COMMAND_DELAY_TIME);
				} while (g_invoke_id<0);
				//	Sleep(1000);
			}
		}




		int ret_scan_count =	m_bac_scan_result_data.size(); 
		if(ret_scan_count == 0 )
		{
			MessageBox(_T("No bacnet mstp device found."));
			return;
		}
		CString bac_strInfo;
		bac_strInfo.Format(_T("Scan  Bacnetip.Found %d recognizable Bacnet device"),ret_scan_count);
		//pScan->ShowBacnetComScanInfo(bac_strInfo);
		TRACE(_T("serial scan = %d\r\n"),ret_scan_count);

		CString strMainBuildName,strSubBuildingName;
		CMainFrame* pFrame=(CMainFrame*)(AfxGetApp()->m_pMainWnd);
		strMainBuildName= pFrame->m_strCurMainBuildingName;
		strSubBuildingName= pFrame->m_strCurSubBuldingName;
		int product_count = pFrame->m_product.size();

		for (int scan_count = 0; scan_count < ret_scan_count ; scan_count ++)
		{
			bool exist_in_db = false;
			int m_product_count = 0;
			for (int a=0;a<product_count;a++)
			{
				if(m_bac_scan_result_data.at(scan_count).serialnumber == pFrame->m_product.at(a).serial_number)
				{
					m_product_count = a;
					exist_in_db = true;
					break;
				}
			}
			CString modbusid;
			CString str_ip_address;
			CString str_n_port;
			CString str_serialid;
			CString product_class_id;
			CString str_product_name;
			CString strSql;
// 			m_pCon.CreateInstance(_T("ADODB.Connection"));
// 			m_pCon->Open(g_strDatabasefilepath.GetString(),_T(""),_T(""),adModeUnknown);

			modbusid.Format(_T("%d"),m_bac_scan_result_data.at(scan_count).modbus_addr);


			str_ip_address.Format(_T("%u.%u.%u.%u"),(unsigned char)m_bac_scan_result_data.at(scan_count).ipaddress[0],
													(unsigned char)m_bac_scan_result_data.at(scan_count).ipaddress[1],
													(unsigned char)m_bac_scan_result_data.at(scan_count).ipaddress[2],
													(unsigned char)m_bac_scan_result_data.at(scan_count).ipaddress[3])  ;
			str_n_port.Format(_T("%d"),m_bac_scan_result_data.at(scan_count).modbus_port);
			str_serialid.Format(_T("%u"),m_bac_scan_result_data.at(scan_count).serialnumber);
			product_class_id.Format(_T("%d"),m_bac_scan_result_data.at(scan_count).product_type);
			str_product_name = GetProductName(m_bac_scan_result_data.at(scan_count).product_type);
			str_product_name = str_product_name + _T(":") + str_serialid + _T("-") + modbusid + _T("-") + str_ip_address;

			if(exist_in_db)
			{
				if((str_ip_address.CompareNoCase(pFrame->m_product.at(m_product_count).BuildingInfo.strIp) != 0) ||
					(m_bac_scan_result_data.at(scan_count).modbus_port != pFrame->m_product.at(m_product_count).ncomport) ||
					(m_bac_scan_result_data.at(scan_count).modbus_addr != pFrame->m_product.at(m_product_count).product_id) ||
					(m_bac_scan_result_data.at(scan_count).device_id != ((int)pFrame->m_product.at(m_product_count).hardware_version )))
				{
					CString instance_value;
					instance_value.Format(_T("%u"),m_bac_scan_result_data.at(scan_count).device_id);
					try
					{
						 
						strSql.Format(_T("update ALL_NODE set Bautrate ='%s' where Serial_ID = '%s'"),str_ip_address,str_serialid);
						bado.m_pConnection->Execute(strSql.GetString(),NULL,adCmdText);		
						strSql.Format(_T("update ALL_NODE set Com_Port ='%s' where Serial_ID = '%s'"),str_n_port,str_serialid);
						bado.m_pConnection->Execute(strSql.GetString(),NULL,adCmdText);		
						strSql.Format(_T("update ALL_NODE set Product_ID ='%s' where Serial_ID = '%s'"),modbusid,str_serialid);
						bado.m_pConnection->Execute(strSql.GetString(),NULL,adCmdText);	
						strSql.Format(_T("update ALL_NODE set Hardware_Ver ='%s' where Serial_ID = '%s'"),instance_value,str_serialid);
						bado.m_pConnection->Execute(strSql.GetString(),NULL,adCmdText);	
					}
					catch(_com_error *e)
					{
						AfxMessageBox(e->ErrorMessage());
					}
					 
					 bado.CloseRecordset();
					 bado.CloseConn();

					pFrame->m_product.at(m_product_count).ncomport = m_bac_scan_result_data.at(scan_count).modbus_port;
					pFrame->m_product.at(m_product_count).BuildingInfo.strIp = str_ip_address;
					pFrame->m_product.at(m_product_count).product_id = m_bac_scan_result_data.at(scan_count).modbus_addr;
				}

			}
			else
			{

			}

		}

	}
}


void CARDDlg::OnCbnDropdownComboProductName()
{
    CString StrSql;
    _variant_t temp_variant;
    Custom_Product_Node product_node;
    m_Custom_Product.clear();
    m_combox_productname.ResetContent();
    CADO bado;
    //bado.SetDBPath(g_strCurBuildingDatabasefilePath);
    bado.OnInitADOConn(); 
    StrSql.Format(_T("Select * From ProductsTypeRegisterTables Where ProductType >=220"));
    bado.m_pRecordset=bado.OpenRecordset(StrSql);
    while(VARIANT_FALSE==bado.m_pRecordset->EndOfFile){
        temp_variant=bado.m_pRecordset->GetCollect("ProductType");//
        if(temp_variant.vt!=VT_NULL)
            product_node.Product_Type=temp_variant;
        else
            product_node.Product_Type=0;

        temp_variant=bado.m_pRecordset->GetCollect("ProductName");//
        if(temp_variant.vt!=VT_NULL)
            product_node.Product_Name=temp_variant;
        else
            product_node.Product_Name=_T("");

            m_Custom_Product.push_back(product_node);
            bado.m_pRecordset->MoveNext();
    }
    bado.CloseRecordset();
    bado.CloseConn();

    for(int i=0;i<(int)m_Custom_Product.size();i++){
        m_combox_productname.AddString(m_Custom_Product.at(i).Product_Name);
    }
}


void CARDDlg::OnCbnSelchangeComboProductName()
{
        int sel = m_combox_productname.GetCurSel();
        CString TypeID;
        TypeID.Format(_T("%d"),m_Custom_Product.at(sel).Product_Type); 
        GetDlgItem(IDC_EDIT_TYPE_ID)->SetWindowText(TypeID);
}


void CARDDlg::OnEnKillfocusEditTypeId()
{
     CString TypeID;
     GetDlgItem(IDC_EDIT_TYPE_ID)->GetWindowText(TypeID);
     if (TypeID.IsEmpty())
     {
          return;
     }
     
     CString ProductName ;
     GetDlgItem(IDC_COMBO_PRODUCT_NAME)->GetWindowText(ProductName);
     int ProductID;
     ProductID = _wtoi(TypeID);
     BOOL Check_Input = FALSE;
     for (int i = 0; i<(int) m_Custom_Product.size();i++)
     {
         if (m_Custom_Product.at(i).Product_Type == ProductID)
         {     Check_Input = TRUE ;
             if (ProductName.CompareNoCase(m_Custom_Product.at(i).Product_Name)!=0)
             {
                 CString strtips;
                 strtips.Format(_T("Product Type :%d have occupied,The Product is %s!"),m_Custom_Product.at(i).Product_Type,m_Custom_Product.at(i).Product_Name);
                 AfxMessageBox(strtips);
                 return;
             }
             break;

         }
         if (ProductName.CompareNoCase(m_Custom_Product.at(i).Product_Name)==0)
         {        Check_Input = TRUE ;
             if (m_Custom_Product.at(i).Product_Type != ProductID)
             {
                 CString strtips;
                 strtips.Format(_T("The Product is %s already in system, Product Type :%d!"),m_Custom_Product.at(i).Product_Type,m_Custom_Product.at(i).Product_Name);
                 AfxMessageBox(strtips);
                 return;
             }
             break;
         }
     }
     if (!Check_Input)
     {
         CString StrSql;
         _variant_t temp_variant;
         Custom_Product_Node product_node;
         m_Custom_Product.clear();
         CADO bado;
         //bado.SetDBPath(g_strCurBuildingDatabasefilePath);
         bado.OnInitADOConn(); 
         StrSql.Format(_T("Insert into ProductsTypeRegisterTables(ProductType,ProductName) Values(%d,'%s')"),ProductID,ProductName);
         bado.m_pRecordset=bado.OpenRecordset(StrSql);
         /*bado.CloseRecordset();*/
         bado.CloseConn();
     }
     


}


//void CARDDlg::OnEnKillfocusEditAddDeviceModbusId()
//{
//    // TODO: Add your control notification handler code here
//}

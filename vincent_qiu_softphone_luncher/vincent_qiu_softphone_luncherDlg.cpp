
// vincent_qiu_softphone_luncherDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "vincent_qiu_softphone_luncher.h"
#include "vincent_qiu_softphone_luncherDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


Cvincent_qiu_softphone_luncherDlg::Cvincent_qiu_softphone_luncherDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cvincent_qiu_softphone_luncherDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cvincent_qiu_softphone_luncherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cvincent_qiu_softphone_luncherDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cvincent_qiu_softphone_luncherDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &Cvincent_qiu_softphone_luncherDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &Cvincent_qiu_softphone_luncherDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// Cvincent_qiu_softphone_luncherDlg 消息处理程序

BOOL Cvincent_qiu_softphone_luncherDlg::OnInitDialog()
{
	bool haskeys = false;
	HKEY hKEY; //定义有关的 hKEY, 在查询结束时要关闭。 
	LPCTSTR data_Set=_T("CounterPath\\RegNow Enhanced\\"); 
	//打开与路径 data_Set 相关的 hKEY，第一个参数为根键名称，第二个参数表。 
	//表示要访问的键的位置，第三个参数必须为0，KEY_READ表示以查询的方式。 
	//访问注册表，hKEY则保存此函数所打开的键的句柄。 
	long ret0=(::RegOpenKeyEx(HKEY_CURRENT_USER,data_Set, 0, KEY_READ, &hKEY)); 
	if(ret0!=ERROR_SUCCESS) //如果无法打开hKEY，则终止程序的执行 
	{
		haskeys = false;
	}
	else
	{
		haskeys = true;
	}
	//查询有关的数据 (用户姓名 owner_Get)。
	TCHAR owner_Get[162];
	//LPBYTE owner_Get = 
	DWORD type_1=REG_SZ ; DWORD cbData_1=160;  
	//hKEY为刚才RegOpenKeyEx()函数所打开的键的句柄，"RegisteredOwner"。 
	//表示要查 询的键值名，type_1表示查询数据的类型，owner_Get保存所。 
	//查询的数据，cbData_1表示预设置的数据长度。 
	long ret1=::RegQueryValueEx(hKEY,_T("license"), NULL, &type_1, (LPBYTE)owner_Get, &cbData_1); 
	if(ret1!=ERROR_SUCCESS) 
	{ 
		haskeys = false;
	} 
	else
	{
		haskeys = true;
	}

	if (haskeys)
	{
		//if (_tcscmp(owner_Get,L"FU9E8UQKSFUNY73B2TH4CZB9AJ754RX6JTJM45AX-RQTMRQSYNCY48LPDBT247YHP")!=0)
		//{
		//	CString temp;
		//	temp.Format(L"License found but different as pre-active one.\n\nCurrent:%s",owner_Get);
		//	MessageBox(temp,_T("Insteresting!! Different license?!"),4096+32);
		//}
		//else
		//{
		//	MessageBox(L"Your license seems correct.");
		//	exit(0);
		//	CString   Path; 
		//	GetCurrentDirectory(MAX_PATH,Path.GetBufferSetLength(MAX_PATH+1));//得到文件绝对路径 
		//	::ShellExecute(this->m_hWnd,(LPCTSTR)L"open",Path + L"\eyeBeam.exe",NULL,NULL,0);
		//	exit(0);
		//}
	}
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CString param = L"-Auto";
	int result = param.Compare(AfxGetApp ()->m_lpCmdLine );
	if (result==0)
	{
		OnBnClickedButton1();
		//OnBnClickedButton3();
		exit(result);
	}


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cvincent_qiu_softphone_luncherDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cvincent_qiu_softphone_luncherDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//
//LPBYTE CString_To_LPBYTE(CString str) 
//{ 
//	LPBYTE lpb=new wchar_t[str.GetLength()+1];  
//	for(int i=0;(i<str.GetLength())&&(*(lpb+i) = str.GetAt(i));i++)
//		return lpb;
//} 

CString Cvincent_qiu_softphone_luncherDlg::GetCurDir() 
{ 
	TCHAR sDrive[_MAX_DRIVE]; 
	TCHAR   sDir[_MAX_DIR]; 
	TCHAR   sFilename[_MAX_FNAME],Filename[_MAX_FNAME]; 
	TCHAR   sExt[_MAX_EXT]; 
	GetModuleFileName(AfxGetInstanceHandle(),   Filename,   _MAX_PATH); 
	_tsplitpath(Filename,   sDrive,   sDir,   sFilename,   sExt); 
	CString   homeDir(CString(sDrive)   +   CString(sDir)); 
	int   nLen   =   homeDir.GetLength(); 
	if(homeDir.GetAt(nLen-1)   !=   _T( '\\ ')) 
		homeDir   +=   _T( '\\ '); 
	return   homeDir; 
}

void Cvincent_qiu_softphone_luncherDlg::OnBnClickedButton1()
{
	{
		HKEY hKEY; //定义有关的 hKEY, 在查询结束时要关闭。 
		DWORD dwDisp;
		LPCTSTR data_Set=_T("CounterPath\\RegNow Enhanced\\"); 
		//打开与路径 data_Set 相关的 hKEY，第一个参数为根键名称，第二个参数表。 
		//表示要访问的键的位置，第三个参数必须为0，KEY_READ表示以查询的方式。 
		//访问注册表，hKEY则保存此函数所打开的键的句柄。 
		long ret0=(::RegOpenKeyEx(HKEY_CURRENT_USER,data_Set, 0, KEY_WRITE, &hKEY)); 
		if(ret0!=ERROR_SUCCESS) //如果无法打开hKEY，则终止程序的执行 
		{
			ret0 = ::RegCreateKeyEx(HKEY_CURRENT_USER,data_Set,0,NULL,REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&hKEY,&dwDisp);
			if (ret0!=ERROR_SUCCESS)
			{
				MessageBox(_T("Active failed, can not write subkey! Please contact v.qiu@directhr.cn"),_T("Active Phone License"),4096+16);
				return;
			}

		}
		CString key = _T("FU9E8UQKSFUNY73B2TH4CZB9AJ754RX6JTJM45AX-RQTMRQSYNCY48LPDBT247YHP");
		//LPBYTE owner_Set=CString_To_LPBYTE(key); 
		//DWORD type_1=REG_SZ; 
		//DWORD cbData_1=key.GetLength()+1;

		//与RegQureyValueEx()类似，hKEY表示已打开的键的句柄，"RegisteredOwner" 
		//表示要访问的键值名，owner_Set表示新的键值，type_1和cbData_1表示新值。 
		//的数据类型和数据长度 
		long ret1=::RegSetValueEx(hKEY, _T("license"), NULL, REG_SZ, (LPBYTE)(LPCTSTR)key, (key.GetLength()+1)*2); 
		if(ret1!=ERROR_SUCCESS) 
		{ 
			MessageBox(_T("Active failed, can not write key! Please contact v.qiu@directhr.cn"),_T("Active Phone License"),4096+16);
		}
		else
		{
			//MessageBox(_T("Active successful!"),_T("Active Phone License"),4096+64);
		}
	}



	{
		HKEY hKEY; //定义有关的 hKEY, 在查询结束时要关闭。 
		DWORD dwDisp;
		LPCTSTR data_Set=_T("sip\\shell\\open\\command\\"); 
		//打开与路径 data_Set 相关的 hKEY，第一个参数为根键名称，第二个参数表。 
		//表示要访问的键的位置，第三个参数必须为0，KEY_READ表示以查询的方式。 
		//访问注册表，hKEY则保存此函数所打开的键的句柄。 
		long ret0=(::RegOpenKeyEx(HKEY_CLASSES_ROOT,data_Set, 0, KEY_WRITE, &hKEY)); 
		if(ret0!=ERROR_SUCCESS) //如果无法打开hKEY，则终止程序的执行 
		{
			ret0 = ::RegCreateKeyEx(HKEY_CLASSES_ROOT,data_Set,0,NULL,REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&hKEY,&dwDisp);
			if (ret0!=ERROR_SUCCESS)
			{
				MessageBox(_T("Failed to check SIP reg status. Please contact v.qiu@directhr.cn"),_T("Active SIP Click Call"),4096+16);
				return;
			}

		}
		//"C:\Program Files (x86)\Softphone\eyeBeam.exe" -dial="%1"
		CString key = _T("\"") + GetCurDir() + _T("eyebeam.exe\" -dial=\"%1\"");
		//LPBYTE owner_Set=CString_To_LPBYTE(key); 
		//DWORD type_1=REG_SZ; 
		//DWORD cbData_1=key.GetLength()+1;

		//与RegQureyValueEx()类似，hKEY表示已打开的键的句柄，"RegisteredOwner" 
		//表示要访问的键值名，owner_Set表示新的键值，type_1和cbData_1表示新值。 
		//的数据类型和数据长度 
		long ret1=::RegSetValueEx(hKEY, _T(""), NULL, REG_SZ, (LPBYTE)(LPCTSTR)key, (key.GetLength()+1)*2); 
		if(ret1!=ERROR_SUCCESS) 
		{ 
			MessageBox(_T("Active failed, can not write key! Please contact v.qiu@directhr.cn"),_T("Active SIP Click Call"),4096+16);
		}
		else
		{
			//MessageBox(_T("Active successful!"),_T("Active SIP Click Call"),4096+64);
		}
	}

	//SIP Support in IE
	{
		HKEY hKEY; //定义有关的 hKEY, 在查询结束时要关闭。 
		DWORD dwDisp;
		LPCTSTR data_Set=_T("sip\\"); 
		//打开与路径 data_Set 相关的 hKEY，第一个参数为根键名称，第二个参数表。 
		//表示要访问的键的位置，第三个参数必须为0，KEY_READ表示以查询的方式。 
		//访问注册表，hKEY则保存此函数所打开的键的句柄。 
		long ret0=(::RegOpenKeyEx(HKEY_CLASSES_ROOT,data_Set, 0, KEY_WRITE, &hKEY)); 
		if(ret0!=ERROR_SUCCESS) //如果无法打开hKEY，则终止程序的执行 
		{
			ret0 = ::RegCreateKeyEx(HKEY_CLASSES_ROOT,data_Set,0,NULL,REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&hKEY,&dwDisp);
			if (ret0!=ERROR_SUCCESS)
			{
				//MessageBox(_T("Failed to check SIP reg status. Please contact v.qiu@directhr.cn"),_T("Active SIP Click Call"),4096+16);
				return;
			}

		}
		//"C:\Program Files (x86)\Softphone\eyeBeam.exe" -dial="%1"
		CString key = GetCurDir() + _T("eyebeam.exe");
		CString sip_protocol = _T("DirectHR SIP Protocol");
		//LPBYTE owner_Set=CString_To_LPBYTE(key); 
		//DWORD type_1=REG_SZ; 
		//DWORD cbData_1=key.GetLength()+1;

		//与RegQureyValueEx()类似，hKEY表示已打开的键的句柄，"RegisteredOwner" 
		//表示要访问的键值名，owner_Set表示新的键值，type_1和cbData_1表示新值。 
		//的数据类型和数据长度 
		::RegSetValueEx(hKEY, _T(""), NULL, REG_SZ, (LPBYTE)(LPCTSTR)sip_protocol, (sip_protocol.GetLength()+1)*2); 
		::RegSetValueEx(hKEY, _T("URL Protocol"), NULL, REG_SZ, (LPBYTE)(LPCTSTR)key, (key.GetLength()+1)*2); 
		::RegSetValueEx(hKEY, _T("DefaultIcon"), NULL, REG_SZ, (LPBYTE)(LPCTSTR)key, (key.GetLength()+1)*2); 
		/*if(ret1!=ERROR_SUCCESS) 
		{ 
		MessageBox(_T("Active failed, can not write key! Please contact v.qiu@directhr.cn"),_T("Active SIP Click Call"),4096+16);
		}
		else
		{
		MessageBox(_T("Active successful!"),_T("Active SIP Click Call"),4096+64);
		}*/
	}

	//IE Right Click Function
	{
		HKEY hKEY; //定义有关的 hKEY, 在查询结束时要关闭。 
		DWORD dwDisp;
		LPCTSTR data_Set=_T("Software\\Microsoft\\Internet Explorer\\MenuExt\\Dial Selected Number"); 
		//打开与路径 data_Set 相关的 hKEY，第一个参数为根键名称，第二个参数表。 
		//表示要访问的键的位置，第三个参数必须为0，KEY_READ表示以查询的方式。 
		//访问注册表，hKEY则保存此函数所打开的键的句柄。 
		long ret0=(::RegOpenKeyEx(HKEY_CURRENT_USER,data_Set, 0, KEY_WRITE, &hKEY)); 
		if(ret0!=ERROR_SUCCESS) //如果无法打开hKEY，则终止程序的执行 
		{
			ret0 = ::RegCreateKeyEx(HKEY_CURRENT_USER,data_Set,0,NULL,REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&hKEY,&dwDisp);
			if (ret0!=ERROR_SUCCESS)
			{
				//MessageBox(_T("Failed to check SIP reg status. Please contact v.qiu@directhr.cn"),_T("Active SIP Click Call"),4096+16);
				return;
			}

		}
		//"C:\Program Files (x86)\Softphone\eyeBeam.exe" -dial="%1"
		CString key = GetCurDir() + _T("rightclick_ie_dialDirectly.html");
		

		//与RegQureyValueEx()类似，hKEY表示已打开的键的句柄，"RegisteredOwner"
		//表示要访问的键值名，owner_Set表示新的键值，type_1和cbData_1表示新值。
		//的数据类型和数据长度
		::RegSetValueEx(hKEY, _T(""), NULL, REG_SZ, (LPBYTE)(LPCTSTR)key, (key.GetLength()+1)*2); 
		::RegSetValueEx(hKEY, _T("Contexts"), 0, REG_DWORD, (const unsigned char*)"0", sizeof(DWORD));
		/*if(ret1!=ERROR_SUCCESS) 
		{ 
		MessageBox(_T("Active failed, can not write key! Please contact v.qiu@directhr.cn"),_T("Active SIP Click Call"),4096+16);
		}
		else
		{
		MessageBox(_T("Active successful!"),_T("Active SIP Click Call"),4096+64);
		}*/
	}

		//IE Right Click Function
	{
		HKEY hKEY; //定义有关的 hKEY, 在查询结束时要关闭。 
		DWORD dwDisp;
		LPCTSTR data_Set=_T("Software\\Microsoft\\Internet Explorer\\MenuExt\\Dial Number With 0 Before"); 
		//打开与路径 data_Set 相关的 hKEY，第一个参数为根键名称，第二个参数表。 
		//表示要访问的键的位置，第三个参数必须为0，KEY_READ表示以查询的方式。 
		//访问注册表，hKEY则保存此函数所打开的键的句柄。 
		long ret0=(::RegOpenKeyEx(HKEY_CURRENT_USER,data_Set, 0, KEY_WRITE, &hKEY)); 
		if(ret0!=ERROR_SUCCESS) //如果无法打开hKEY，则终止程序的执行 
		{
			ret0 = ::RegCreateKeyEx(HKEY_CURRENT_USER,data_Set,0,NULL,REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&hKEY,&dwDisp);
			if (ret0!=ERROR_SUCCESS)
			{
				//MessageBox(_T("Failed to check SIP reg status. Please contact v.qiu@directhr.cn"),_T("Active SIP Click Call"),4096+16);
				return;
			}

		}
		//"C:\Program Files (x86)\Softphone\eyeBeam.exe" -dial="%1"
		CString key = GetCurDir() + _T("rightclick_ie_dialwithZero.html");
		

		//与RegQureyValueEx()类似，hKEY表示已打开的键的句柄，"RegisteredOwner" 
		//表示要访问的键值名，owner_Set表示新的键值，type_1和cbData_1表示新值。 
		//的数据类型和数据长度 
		::RegSetValueEx(hKEY, _T(""), NULL, REG_SZ, (LPBYTE)(LPCTSTR)key, (key.GetLength()+1)*2); 
		::RegSetValueEx(hKEY, _T("Contexts"), 0, REG_DWORD, (const unsigned char*)"0", sizeof(DWORD));
		/*if(ret1!=ERROR_SUCCESS) 
		{ 
		MessageBox(_T("Active failed, can not write key! Please contact v.qiu@directhr.cn"),_T("Active SIP Click Call"),4096+16);
		}
		else
		{
		MessageBox(_T("Active successful!"),_T("Active SIP Click Call"),4096+64);
		}*/
	}

		//IE Right Click Function
	{
		HKEY hKEY; //定义有关的 hKEY, 在查询结束时要关闭。 
		DWORD dwDisp;
		LPCTSTR data_Set=_T("Software\\Microsoft\\Internet Explorer\\MenuExt\\Edit Number Before Dial"); 
		//打开与路径 data_Set 相关的 hKEY，第一个参数为根键名称，第二个参数表。 
		//表示要访问的键的位置，第三个参数必须为0，KEY_READ表示以查询的方式。 
		//访问注册表，hKEY则保存此函数所打开的键的句柄。 
		long ret0=(::RegOpenKeyEx(HKEY_CURRENT_USER,data_Set, 0, KEY_WRITE, &hKEY)); 
		if(ret0!=ERROR_SUCCESS) //如果无法打开hKEY，则终止程序的执行 
		{
			ret0 = ::RegCreateKeyEx(HKEY_CURRENT_USER,data_Set,0,NULL,REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&hKEY,&dwDisp);
			if (ret0!=ERROR_SUCCESS)
			{
				//MessageBox(_T("Failed to check SIP reg status. Please contact v.qiu@directhr.cn"),_T("Active SIP Click Call"),4096+16);
				return;
			}

		}
		//"C:\Program Files (x86)\Softphone\eyeBeam.exe" -dial="%1"
		CString key = GetCurDir() + _T("rightclick_ie_editBeforeDial.html");
		

		//与RegQureyValueEx()类似，hKEY表示已打开的键的句柄，"RegisteredOwner" 
		//表示要访问的键值名，owner_Set表示新的键值，type_1和cbData_1表示新值。 
		//的数据类型和数据长度 
		::RegSetValueEx(hKEY, _T(""), NULL, REG_SZ, (LPBYTE)(LPCTSTR)key, (key.GetLength()+1)*2); 
		::RegSetValueEx(hKEY, _T("Contexts"), 0, REG_DWORD, (const unsigned char*)"0", sizeof(DWORD));
		/*if(ret1!=ERROR_SUCCESS) 
		{ 
		MessageBox(_T("Active failed, can not write key! Please contact v.qiu@directhr.cn"),_T("Active SIP Click Call"),4096+16);
		}
		else
		{
		MessageBox(_T("Active successful!"),_T("Active SIP Click Call"),4096+64);
		}*/
	}


		{
		HKEY hKEY; //定义有关的 hKEY, 在查询结束时要关闭。 
		DWORD dwDisp;
		LPCTSTR data_Set=_T("Software\\Microsoft\\Internet Explorer\\MenuExt\\Edit Number Before Dial"); 
		//打开与路径 data_Set 相关的 hKEY，第一个参数为根键名称，第二个参数表。 
		//表示要访问的键的位置，第三个参数必须为0，KEY_READ表示以查询的方式。 
		//访问注册表，hKEY则保存此函数所打开的键的句柄。 
		long ret0=(::RegOpenKeyEx(HKEY_CURRENT_USER,data_Set, 0, KEY_WRITE, &hKEY)); 
		if(ret0!=ERROR_SUCCESS) //如果无法打开hKEY，则终止程序的执行 
		{
			ret0 = ::RegCreateKeyEx(HKEY_CURRENT_USER,data_Set,0,NULL,REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&hKEY,&dwDisp);
			if (ret0!=ERROR_SUCCESS)
			{
				//MessageBox(_T("Failed to check SIP reg status. Please contact v.qiu@directhr.cn"),_T("Active SIP Click Call"),4096+16);
				return;
			}

		}
		//"C:\Program Files (x86)\Softphone\eyeBeam.exe" -dial="%1"
		CString key = GetCurDir() + _T("rightclick_ie_editBeforeDial.html");
		

		//与RegQureyValueEx()类似，hKEY表示已打开的键的句柄，"RegisteredOwner" 
		//表示要访问的键值名，owner_Set表示新的键值，type_1和cbData_1表示新值。 
		//的数据类型和数据长度 
		::RegSetValueEx(hKEY, _T(""), NULL, REG_SZ, (LPBYTE)(LPCTSTR)key, (key.GetLength()+1)*2); 
		::RegSetValueEx(hKEY, _T("Contexts"), 0, REG_DWORD, (const unsigned char*)"0", sizeof(DWORD));
		/*if(ret1!=ERROR_SUCCESS) 
		{ 
		MessageBox(_T("Active failed, can not write key! Please contact v.qiu@directhr.cn"),_T("Active SIP Click Call"),4096+16);
		}
		else
		{
		MessageBox(_T("Active successful!"),_T("Active SIP Click Call"),4096+64);
		}*/
	}

		/*
		Open Google Chrome to install plugin */
		//MessageBox(L"In the next window, please install the telephone plugin in Google Chrome!",_T("Google Chrome Plugin Installer"),4096+64);
		system("icacls %windir%\\system32\\drivers\\etc\\hosts /grant Users:(F)");
		ShellExecute(NULL,L"open",L"chrome.exe",L"https://chrome.google.com/webstore/detail/mapjclclndigebgobdncmlhmpmnhmpma",NULL,0);
		OnBnClickedButton3();
}


void Cvincent_qiu_softphone_luncherDlg::OnBnClickedOk()
{
	system("icacls %windir%\\system32\\drivers\\etc\\hosts /grant Users:(F)");
}


void Cvincent_qiu_softphone_luncherDlg::OnBnClickedButton3()
{
	/*
	INSTALL DIRVERS
	*/
    typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL); 
    LPFN_ISWOW64PROCESS fnIsWow64Process; 
    BOOL bIsWow64 = FALSE; 
    fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress( GetModuleHandle(_T("kernel32")),"IsWow64Process"); 
    if (NULL != fnIsWow64Process) 
    { 
        fnIsWow64Process(GetCurrentProcess(),&bIsWow64);
    }
	system("netcfg.exe -v -u \"dhr_qzjndis\" >nul");
	if (bIsWow64)
	{
		//Install x64 driver
		system("netcfg.exe -l Drivers\\x64\\qzjndis.inf -c s -i \"dhr_qzjndis\" >nul");
	}
	else
	{
		//Install x86 driver
		//AfxMessageBox(_T("Please notice that you are running 32bit system, the program haven't been test it in 32bit yet!"));
		system("netcfg.exe -l Drivers\\x86\\qzjndis.inf -c s -i \"dhr_qzjndis\" >nul");
	}
}

// vincent_qiu_softphone_luncherDlg.h : 头文件
//

#pragma once


// Cvincent_qiu_softphone_luncherDlg 对话框
class Cvincent_qiu_softphone_luncherDlg : public CDialogEx
{
// 构造
public:
	Cvincent_qiu_softphone_luncherDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_VINCENT_QIU_SOFTPHONE_LUNCHER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CString GetCurDir();
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
};

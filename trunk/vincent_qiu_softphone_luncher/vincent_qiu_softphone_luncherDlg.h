
// vincent_qiu_softphone_luncherDlg.h : ͷ�ļ�
//

#pragma once


// Cvincent_qiu_softphone_luncherDlg �Ի���
class Cvincent_qiu_softphone_luncherDlg : public CDialogEx
{
// ����
public:
	Cvincent_qiu_softphone_luncherDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_VINCENT_QIU_SOFTPHONE_LUNCHER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CString GetCurDir();
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
};

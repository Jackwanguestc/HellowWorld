#pragma once


// editSend �Ի���

class editSend : public CDialogEx
{
	DECLARE_DYNAMIC(editSend)

public:
	editSend(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~editSend();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

// editSend.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ClipBoard.h"
#include "editSend.h"
#include "afxdialogex.h"


// editSend �Ի���

IMPLEMENT_DYNAMIC(editSend, CDialogEx)

editSend::editSend(CWnd* pParent /*=NULL*/)
	: CDialogEx(editSend::IDD, pParent)
{

}

editSend::~editSend()
{
}

void editSend::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(editSend, CDialogEx)
	ON_BN_CLICKED(IDOK, &editSend::OnBnClickedOk)
END_MESSAGE_MAP()


// editSend ��Ϣ�������


void editSend::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}

// editSend.cpp : 实现文件
//

#include "stdafx.h"
#include "ClipBoard.h"
#include "editSend.h"
#include "afxdialogex.h"


// editSend 对话框

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


// editSend 消息处理程序


void editSend::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

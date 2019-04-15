
// yaoshande2Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "yaoshande2.h"
#include "yaoshande2Dlg.h"
#include "afxdialogex.h"
#include<fstream>
#include <stdio.h>
#include<string>
#include<iostream>
#ifdef _DEBUG
#define new DEBUG_NEW 
#endif
using namespace std;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

int count(int m, int n, int l, int c, int x, int y)
{
	int p = 0, r = 0;
	if (c == 0)
	{
		if (x == 0)
		{
			p = m + n;
			cout << "ok";

		}

		else  if (x == 1)
		{
			p = m - n;
		}

		else  if (x == 2)
		{
			p = m * n;
		}
		else if (x == 3)
		{
			p = m / n;
		}

		if (y == 0)
		{
			p = p + l;

		}

		else  if (y == 1)
		{
			p = p - l;
		}

		else  if (y == 2)
		{
			p = p * l;
		}
		else if (y == 3)
		{
			p = p / l;
		}
	}
	if (c == 1)
	{


		if (y == 2)
		{
			p = n * l;
		}
		else if (y == 3)
		{
			p = n / l;
		}

		if (x == 0)
		{
			p = p + m;

		}

		else  if (x == 1)
		{
			p = p - m;
		}

	}r = p;
	return r;
}


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cyaoshande2Dlg 对话框



Cyaoshande2Dlg::Cyaoshande2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_YAOSHANDE2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cyaoshande2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cyaoshande2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Cyaoshande2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &Cyaoshande2Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT4, &Cyaoshande2Dlg::OnEnChangeEdit4)
END_MESSAGE_MAP()


// Cyaoshande2Dlg 消息处理程序

BOOL Cyaoshande2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MAXIMIZE);

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cyaoshande2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cyaoshande2Dlg::OnPaint()
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
HCURSOR Cyaoshande2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cyaoshande2Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void Cyaoshande2Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//FILE *fp;
	//char fname[32];/*文件名*/
	//printf("请输入文件名\n");
	//scanf("%s", fname);/*输入文件名*/
	//strcat(fname, ".txt");
	//fp = fopen(fname, "a");
	//fclose(fp);


	//char* path = "F:\\work\\1.text";
	//	FILE*fp = NULL;//需要注意
	//	fp = fopen(path, "w");  //创建文件
	//	//if (NULL == fp) return -1;//要返回错误代码
	////	while (scanf("%c", &c) != EOF) fprintf(fp, "%c", c); //从控制台中读入并在文本输出
	//	fclose(fp);
	//	fp = NULL;//需要指向空，否则会指向原打开文件地址 


	string file = {"题目和答案"};
	ofstream fout(file.c_str());
	CString str;
	
		int i, a[101][6],  k=5, j,b, l, m, n, s, x, y, c;
		 //char b=str;
		GetDlgItem(IDC_EDIT4)->GetWindowText(str);
	b = _ttol(str);
		for (i = 0; i < b; i++)
		{

			m = (rand() % 100); a[i][0] = m; a[i][0] = m;
			n = (rand() % 100); a[i][1] = n; a[i][1] = n;
			l = (rand() % 100); a[i][2] = l; a[i][2] = l;
			//cout << l;
			x = rand() % 4; a[i][3] = x;
			y = rand() % 4; a[i][4] = y;
			if (x == 0)
			{
				fout << m << " + " << n;

			}

			else  if (x == 1)
			{
				fout << m << " - " << n;
			}

			else  if (x == 2)
			{
				fout << m << " X " << n;
			}
			else if (x == 3)
			{
				fout << m << "÷" << n;
			}

			if (y == 0)
			{
				fout << " + " << l;

			}

			else  if (y == 1)
			{
				fout << " - " << l;
			}

			else  if (y == 2)
			{
				fout << " X " << l;
			}
			else if (y == 3)
			{
				fout << "÷" << l;
			}

			fout << " =" << endl;

			if ((y >= 2) && (x <= 1))
			{
				c = 1;
				a[i][5] = c;

			}
			else
			{
				c = 0;
			}a[i][5] = c;
		}

		for (j = 0; j < b; j++)
		{
			s = count(a[j][0], a[j][1], a[j][2], a[j][5], a[j][3], a[j][4]);
			fout << "答案是" << s << endl;
		}



		
	
	
		//fout << "111";
		fout.close();
}


void Cyaoshande2Dlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	//CString str;
	//GetDlgItem(IDC_EDIT4)->GetWindowText(str);

}

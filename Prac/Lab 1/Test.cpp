#include "stdarg.h"
#include<iostream>
#include<string>
#include<io.h>
#include<fcntl.h>
#include<Windows.h>

using namespace std;
class Students {
	int code;
	wstring fullname;
	wstring phonenumber;
	wstring birthday;
public:
	void getData();
	void setData();
};
void Students::setData() {
	wcout << L"Nhập mã sinh viên: ";
	cin >> code;
	wcout << L"Nhập tên sinh viên: ";
	getline(wcin >> ws, fullname);
	wcout << L"Nhập số điện thoại: ";
	getline(wcin>>ws, phonenumber);
	wcout << L"Nhập ngày sinh: ";
	getline(wcin >> ws, birthday);
}
void Students::getData() {
	wcout << L"Mã sinh viên: "<< code << endl;
	wcout << L"Họ tên: " << fullname << endl;
	wcout << L"Số điện thoại: " << phonenumber << endl;
	wcout << L"Ngày sinh: " << birthday << endl;
}

int main()
{
a	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	HANDLE hdlconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX consoleFont;
	consoleFont.cbSize = sizeof(consoleFont);
	GetCurrentConsoleFontEx(hdlconsole, FALSE, &consoleFont);
	memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
	Students *sv = new Students;
	int n;
	wcout << L"Nhập số lượng sinh viên: "; cin >> n;
	for (int i = 0; i < n; i++) {
		wcout << L"Nhập thông tin sinh viên thứ " << i + 1 <<": "<< endl;
		sv->setData();
	}
	wcout << L"--------Danh sách sinh viên---------" << endl;
	for (int i = 0; i < n; i++) {
		sv->getData();
	}
	return 0;
}

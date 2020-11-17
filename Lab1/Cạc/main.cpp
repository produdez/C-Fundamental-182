#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream ipf;
    ipf.open("test", ios::in | ios::out);
    ipf.seekg(2,ios::beg);//đặt get-pointer đến byte thứ 2
    cout << ipf.tellg();//Xem get-pointer ở đâu, byte tính theo mỗi byte 1 ký tự
    ipf.put('X');
    ipf.close();
    return 0;
}

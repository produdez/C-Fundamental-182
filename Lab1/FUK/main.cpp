#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    fstream ipf("test.txt", ios::in | ios::out);
    ipf.seekg(2,ios::beg);//đặt get-pointer đến byte thứ 2
    cout << ipf.tellg();//Xem get-pointer ở đâu, byte tính theo mỗi byte 1 ký tự
    ipf.put('X');
    return 0;
}

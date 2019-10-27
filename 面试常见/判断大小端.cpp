#include <bits/stdc++.h>

using namespace std;

void checkCPU()
{
    union temp
	{
		int a;
		char b;
	}temp;
	temp.a = 0x1234;    //int是四个字节，32位
    //这里不关char一个字节的事，ASCII需要两位16进制，所以会根据ASCII表对0x12或0x34进行转换
    cout << temp.b << " " << (int)temp.b << endl;
	if( temp.b == 0x34 )//低字节存的是数据的高字节数据
		cout << "little endian" <<endl;
	else if(temp.b == 0x12)
		cout << "big endian" <<endl;
}

int main()
{
    checkCPU();
    int a = 0x21;
    cout << a << " " << (char)a;//根据ASCII表转换，并不是看末位
    return 0;
}
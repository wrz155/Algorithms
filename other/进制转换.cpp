#include <stdio.h>   
#include <string.h>  
#include <iostream>  
using namespace std;
/////////////////////////////////////////////////////   
//   
//功能：二进制取反   
//   
//输入：const unsigned char *src  二进制数据   
//      int length                待转换的二进制数据长度   
//   
//输出：unsigned char *dst        取反后的二进制数据   
//   
//返回：0    success   
//   
//////////////////////////////////////////////////////   
int convert(unsigned char *dst, const unsigned char *src, int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		dst[i] = src[i] ^ 0xFF;
	}
	return 0;
}
//////////////////////////////////////////////////////////   
//   
//功能：十六进制转为十进制   
//   
//输入：const unsigned char *hex         待转换的十六进制数据   
//      int length                       十六进制数据长度   
//   
//输出：   
//   
//返回：int  rslt                        转换后的十进制数据   
//   
//思路：十六进制每个字符位所表示的十进制数的范围是0 ~255，进制为256   
//      左移8位(<<8)等价乘以256   
//   
/////////////////////////////////////////////////////////   
unsigned long HextoDec(const unsigned char *hex, int length)
{
	int i;
	unsigned long rslt = 0;
	for (i = 0; i < length; i++)
	{
		rslt += (unsigned long)(hex[i]) << (8 * (length - 1 - i));

	}
	return rslt;
}

/////////////////////////////////////////////////////////   
//   
//功能：十进制转十六进制   
//   
//输入：int dec                     待转换的十进制数据   
//      int length                  转换后的十六进制数据长度   
//   
//输出：unsigned char *hex          转换后的十六进制数据   
//   
//返回：0    success   
//   
//思路：原理同十六进制转十进制   
//////////////////////////////////////////////////////////   
int DectoHex(int dec, unsigned char *hex, int length)
{
	int i;
	for (i = length - 1; i >= 0; i--)
	{
		hex[i] = (dec % 256) & 0xFF;
		dec /= 256;
	}
	return 0;
}
/////////////////////////////////////////////////////////   
//   
//功能：求权   
//   
//输入：int base                    进制基数   
//      int times                   权级数   
//   
//输出：   
//   
//返回：unsigned long               当前数据位的权   
//   
//////////////////////////////////////////////////////////   
unsigned long power(int base, int times)
{
	int i;
	unsigned long rslt = 1;
	for (i = 0; i < times; i++)
		rslt *= base;
	return rslt;
}
/////////////////////////////////////////////////////////   
//   
//功能：BCD转10进制   
//   
//输入：const unsigned char *bcd     待转换的BCD码   
//      int length                   BCD码数据长度   
//   
//输出：   
//   
//返回：unsigned long               当前数据位的权   
//   
//思路：压缩BCD码一个字符所表示的十进制数据范围为0 ~ 99,进制为100   
//      先求每个字符所表示的十进制值，然后乘以权   
//////////////////////////////////////////////////////////   
unsigned long  BCDtoDec(const unsigned char *bcd, int length)
{
	int i, tmp;
	unsigned long dec = 0;
	for (i = 0; i < length; i++)
	{
		tmp = ((bcd[i] >> 4) & 0x0F) * 10 + (bcd[i] & 0x0F);
		dec += tmp * power(100, length - 1 - i);
	}
	return dec;
}
/////////////////////////////////////////////////////////   
//   
//功能：十进制转BCD码   
//   
//输入：int Dec                      待转换的十进制数据   
//      int length                   BCD码数据长度   
//   
//输出：unsigned char *Bcd           转换后的BCD码   
//   
//返回：0  success   
//   
//思路：原理同BCD码转十进制   
//   
//////////////////////////////////////////////////////////   
int DectoBCD(int Dec, unsigned char *Bcd, int length)
{
	int i;
	int temp;
	for (i = length - 1; i >= 0; i--)
	{
		temp = Dec % 100;
		Bcd[i] = ((temp / 10) << 4) + ((temp % 10) & 0x0F);
		Dec /= 100;
	}
	return 0;
}
//main函数  
int main(int argc, char** argv)
{
	//BCD码转十进制   
	unsigned char BCD[3] = { 0x00, 0x53, 0x20 };
	int dec_bcd = BCDtoDec(BCD, 3);
	cout << "dec_bcd : " << dec_bcd << endl;

	//十进制转BCD码  
	unsigned char tmp_bff[3] = "";
	DectoBCD(dec_bcd, tmp_bff, 3);
	for (int i = 0; i < 3; ++i)
	{
		//cout << "tmp_buff[" << i << "]: " << tmp_bff[i] << endl;  
		printf("tmp_bff[%d] = 0x%02X\n", i, tmp_bff[i]);
	}

	cout << endl << endl;
	//十六进制转十进制  
	unsigned char Hex[3] = { 0x00, 0x53, 0x20 };
	int dec_hex = HextoDec(Hex, 3);
	cout << "dec_hex: " << dec_hex << endl;

	//十进制转十六进制  
	unsigned char hex_bff[3] = "";
	DectoHex(dec_hex, hex_bff, 3);
	for (int i = 0; i < 3; ++i)
	{
		printf("hex_bff[%d] = 0x%02X\n", i, hex_bff[i]);
	}

	system("pause");
	return 0;
}
#include <stdio.h>   
#include <string.h>  
#include <iostream>  
using namespace std;
/////////////////////////////////////////////////////   
//   
//���ܣ�������ȡ��   
//   
//���룺const unsigned char *src  ����������   
//      int length                ��ת���Ķ��������ݳ���   
//   
//�����unsigned char *dst        ȡ����Ķ���������   
//   
//���أ�0    success   
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
//���ܣ�ʮ������תΪʮ����   
//   
//���룺const unsigned char *hex         ��ת����ʮ����������   
//      int length                       ʮ���������ݳ���   
//   
//�����   
//   
//���أ�int  rslt                        ת�����ʮ��������   
//   
//˼·��ʮ������ÿ���ַ�λ����ʾ��ʮ�������ķ�Χ��0 ~255������Ϊ256   
//      ����8λ(<<8)�ȼ۳���256   
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
//���ܣ�ʮ����תʮ������   
//   
//���룺int dec                     ��ת����ʮ��������   
//      int length                  ת�����ʮ���������ݳ���   
//   
//�����unsigned char *hex          ת�����ʮ����������   
//   
//���أ�0    success   
//   
//˼·��ԭ��ͬʮ������תʮ����   
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
//���ܣ���Ȩ   
//   
//���룺int base                    ���ƻ���   
//      int times                   Ȩ����   
//   
//�����   
//   
//���أ�unsigned long               ��ǰ����λ��Ȩ   
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
//���ܣ�BCDת10����   
//   
//���룺const unsigned char *bcd     ��ת����BCD��   
//      int length                   BCD�����ݳ���   
//   
//�����   
//   
//���أ�unsigned long               ��ǰ����λ��Ȩ   
//   
//˼·��ѹ��BCD��һ���ַ�����ʾ��ʮ�������ݷ�ΧΪ0 ~ 99,����Ϊ100   
//      ����ÿ���ַ�����ʾ��ʮ����ֵ��Ȼ�����Ȩ   
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
//���ܣ�ʮ����תBCD��   
//   
//���룺int Dec                      ��ת����ʮ��������   
//      int length                   BCD�����ݳ���   
//   
//�����unsigned char *Bcd           ת�����BCD��   
//   
//���أ�0  success   
//   
//˼·��ԭ��ͬBCD��תʮ����   
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
//main����  
int main(int argc, char** argv)
{
	//BCD��תʮ����   
	unsigned char BCD[3] = { 0x00, 0x53, 0x20 };
	int dec_bcd = BCDtoDec(BCD, 3);
	cout << "dec_bcd : " << dec_bcd << endl;

	//ʮ����תBCD��  
	unsigned char tmp_bff[3] = "";
	DectoBCD(dec_bcd, tmp_bff, 3);
	for (int i = 0; i < 3; ++i)
	{
		//cout << "tmp_buff[" << i << "]: " << tmp_bff[i] << endl;  
		printf("tmp_bff[%d] = 0x%02X\n", i, tmp_bff[i]);
	}

	cout << endl << endl;
	//ʮ������תʮ����  
	unsigned char Hex[3] = { 0x00, 0x53, 0x20 };
	int dec_hex = HextoDec(Hex, 3);
	cout << "dec_hex: " << dec_hex << endl;

	//ʮ����תʮ������  
	unsigned char hex_bff[3] = "";
	DectoHex(dec_hex, hex_bff, 3);
	for (int i = 0; i < 3; ++i)
	{
		printf("hex_bff[%d] = 0x%02X\n", i, hex_bff[i]);
	}

	system("pause");
	return 0;
}
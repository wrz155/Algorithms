#include <iostream>
#include <string>
using namespace std;

class Base64 
{
private:
	std::string _base64_table;
	static const char base64_pad = '='; 
public:
	Base64()
	{
		_base64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; /*����Base64����ʹ�õı�׼�ֵ�*/
	}
	/**
	* ���������unsigned���ͣ�����������ĵ�ʱ�����
	*/
	std::string Encode(const unsigned char * str, int length)
	{
		std::string _encode_result;
		const unsigned char * current;
		current = str;
		while (length > 2) {
			_encode_result += _base64_table[current[0] >> 2];
			_encode_result += _base64_table[((current[0] & 0x03) << 4) + (current[1] >> 4)];
			_encode_result += _base64_table[((current[1] & 0x0f) << 2) + (current[2] >> 6)];
			_encode_result += _base64_table[current[2] & 0x3f];

			current += 3;
			length -= 3;
		}
		if (length > 0)
		{
			_encode_result += _base64_table[current[0] >> 2];
			if (length % 3 == 1) {
				_encode_result += _base64_table[(current[0] & 0x03) << 4];
				_encode_result += "==";
			}
			else if (length % 3 == 2) {
				_encode_result += _base64_table[((current[0] & 0x03) << 4) + (current[1] >> 4)];
				_encode_result += _base64_table[(current[1] & 0x0f) << 2];
				_encode_result += "=";
			}
		}
		return _encode_result;
	}
	std::string Decode(const char *str, int length)
	{
			//�����
	const char DecodeTable[] =
	{
		-2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -2, -2, -1, -2, -2,
		-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
		-1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 62, -2, -2, -2, 63,
		52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -2, -2, -2, -2, -2, -2,
		-2,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
		15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -2, -2, -2, -2, -2,
		-2, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
		41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -2, -2, -2, -2, -2,
		-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
		-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
		-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
		-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
		-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
		-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
		-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
		-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2
	};
	int bin = 0, i = 0, pos = 0;
	std::string _decode_result;
	const char *current = str;
	char ch;
	while ((ch = *current++) != '\0' && length-- > 0)
	{
		if (ch == base64_pad) { // ��ǰһ���ַ��ǡ�=����
								/*
								��˵��һ������ڽ���ʱ��4���ַ�Ϊһ�����һ���ַ�ƥ�䡣
								����������
								1�����ĳһ��ƥ��ĵڶ����ǡ�=���ҵ������ַ����ǡ�=����˵������������ַ������Ϸ���ֱ�ӷ��ؿ�
								2�������ǰ��=�����ǵڶ����ַ����Һ�����ַ�ֻ�����հ׷�����˵�������������Ϸ������Լ�����
								*/
			if (*current != '=' && (i % 4) == 1) {
				return NULL;
			}
			continue;
		}
		ch = DecodeTable[ch];
		//�������Ҫ�������������в��Ϸ����ַ�
		if (ch < 0) { /* a space or some other separator character, we simply skip over */
			continue;
		}
		switch (i % 4)
		{
		case 0:
			bin = ch << 2;
			break;
		case 1:
			bin |= ch >> 4;
			_decode_result += bin;
			bin = (ch & 0x0f) << 4;
			break;
		case 2:
			bin |= ch >> 2;
			_decode_result += bin;
			bin = (ch & 0x03) << 6;
			break;
		case 3:
			bin |= ch;
			_decode_result += bin;
			break;
		}
		i++;
	}
	return _decode_result;
	}

};



int Base64_main()
{
	char str[] = "����һ���������ݣ�http://img.v.cmcm.com/7dd6e6d7-0c2d-5a58-a072-71f828b94cbc_crop_216x150.jpg";
	string normal, encoded;
	int len = sizeof(str) - 1;
	Base64 *base = new Base64();
	encoded = base->Encode((unsigned char *)str, len);
	cout << "base64 encode : " << encoded << endl;
	len = encoded.length();
	const char * str2 = encoded.c_str();
	normal = base->Decode(str2, len);
	cout << "base64 decode : " << normal << endl;

	getchar();
	return 0;
}
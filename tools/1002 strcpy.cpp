//链式表达式
#include <iostream>
char * strcpy(char *dst, const char *src)
{
	if (dst == NULL || src == NULL) {
		return NULL;
	}
	char *ret = dst;

	while ((*dst++ = *src++) != '\0');
	return ret;
}

//考虑内存重叠
void* memmove(void* str1, const void* str2, size_t n)
{
	char* pStr1 = (char*)str1;
	const char* pStr2 = (const char*)str2;

	if (pStr1 < pStr2) {
		for (size_t i = 0; i != n; ++i) {
			*(pStr1++) = *(pStr2++);
		}
	}
	else {
		pStr1 += n - 1;
		pStr2 += n - 1;
		for (size_t i = 0; i != n; ++i) {
			*(pStr1--) = *(pStr2--);
		}
	}
	return str1;
}
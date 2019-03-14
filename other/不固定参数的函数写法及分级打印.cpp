#define _CRT_SECURE_NO_WARNINGS

#include <stdarg.h>
#include <filesystem>


#define Log_file "E:\\log.log"
#define Time_len 40
#define Log_len 100

//分级打印制度
int g_iLogLevel = 0;

enum LOG_LEVEL
{
	ERR_NONE = 0,
	ERR_WARNNING = 1,
	ERR_MINOR = 0x1 << 1,
	ERR_MAJOR = 0x1 << 2,
	ERR_FATAL = 0x1 << 3,
	ERR_DEBUG = 0x1 << 4,

	ERR_MAX = 0x1 << 7,
	ERR_ALL = 0xff,
};

#define MY_LOG_PRINT(level, fmt, ...) \
do { \
	if (level & g_iLogLevel) WriteLog(fmt, ##__VA_ARGS__);\
} while (0)


//加上iCnt，防止访问越界
int GetAvg(int iCnt, ...)
{
	int iRet = 0;
	int iTmp = 0;
	int i = iCnt;
	// 1, va_list: 定义一个指针arg  指向函数入参地址
	va_list arg;
	// 2, va_start函数将arg指针指向iCnt后面的参数
	va_start(arg, iCnt);
	while (i--)
	{
		// 3, va_arg函数提取arg指向地址的值，int表明提取的长度以及对提取出来的值做强制转换，提取完之后会自动偏移sizeof(int)
		iTmp = va_arg(arg, int);
		iRet += iTmp;
	}

	// 4, 复位arg指针，重新指向第一个参数
	va_end(arg);
	return iRet / iCnt;
}

int WriteLog(char *pcFmt, ...)
{
	// 1, time_t定义一个整数，从1900年1月1日0点0分0秒到现在的秒数
	time_t tNow;
	// 2, 时间结构体
	struct tm stTime;

	time(&tNow);
	//printf("tNow: %d\n", tNow);
	localtime_s(&stTime, &tNow);

	//printf("Time: %d-%d-%d %d:%d:%d\n", stTime.tm_year + 1900, stTime.tm_mon, stTime.tm_mday, stTime.tm_hour, stTime.tm_min, stTime.tm_sec);
	//打印时间的函数strftime()
	char szTime[Time_len] = { 0 };
	char szLogBuf[Log_len] = { 0 }; //加不加0  数组都会清0
	strftime(szTime, 40, "%Y-%m-%d %X\n", &stTime);
	strftime(szLogBuf, 40, "%Y-%m-%d %X\n", &stTime);
	printf("Time: %s\n", szTime);

	FILE *pFile;
	va_list arg;

	va_start(arg, pcFmt);
	//_snprintf_c(szLogBuf + strlen(szLogBuf), Log_len - strlen(szLogBuf), pcFmt, arg);
	_vsnprintf_c(szLogBuf + strlen(szLogBuf), Log_len - strlen(szLogBuf), pcFmt, arg);

	pFile = fopen(Log_file, "a");//a 追加写入
	if (pFile == NULL)
	{
		return -1;
	}

	fprintf(pFile, "%s\n\r", szLogBuf);

	va_end(arg);
	fclose(pFile);

	return 0;
}

int main()
{
	int iAvg = GetAvg(4, 1, 2, 3, 4);
	printf("%d\n", iAvg);

	WriteLog("%s", "this is test log");


	g_iLogLevel = ERR_MINOR | ERR_FATAL | ERR_WARNNING;
	MY_LOG_PRINT(ERR_WARNNING, "%s", "DEBUG  this is a test log");
	MY_LOG_PRINT(ERR_FATAL, "%s", "fatal  this is a test log");
	MY_LOG_PRINT(ERR_WARNNING, "%s Errcode: %d", "Warnning: this is a test lag", 0x1000001);
	getchar();
	return 0;
}
#include <sys/types.h>  //是Unix/Linux系统的基本系统数据类型的头文件
#include <sys/stat.h>   //获取文件属性
#include <fcntl.h>      //定义了文件操作等所用到的相关宏和open,fcntl函数原型
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ItcastLog.h"

#define ITCAST_DEBUG_FILE_	"socketclient.log" //日志文件名
#define ITCAST_MAX_STRING_LEN 		10240      //日志行数

//Level类别
#define IC_NO_LOG_LEVEL			0
#define IC_DEBUG_LEVEL			1
#define IC_INFO_LEVEL			2
#define IC_WARNING_LEVEL		3
#define IC_ERROR_LEVEL			4

//Level数组
int  LogLevel[5] = {IC_NO_LOG_LEVEL, IC_DEBUG_LEVEL, IC_INFO_LEVEL, IC_WARNING_LEVEL, IC_ERROR_LEVEL};

//Level的名称
char ICLevelName[5][10] = {"NOLOG", "DEBUG", "INFO", "WARNING", "ERROR"};

//加static内部函数
static int ITCAST_Error_GetCurTime(char* strTime)
{
	struct tm*		tmTime = NULL;
	size_t			timeLen = 0;
	time_t			tTime = 0;	
	
	tTime = time(NULL);        //调用time.h获取时间结构体指针
	tmTime = localtime(&tTime);//转换时间为str类型
	//timeLen = strftime(strTime, 33, "%Y(Y)%m(M)%d(D)%H(H)%M(M)%S(S)", tmTime);
	timeLen = strftime(strTime, 33, "%Y.%m.%d %H:%M:%S", tmTime);//获取时间长度
	return timeLen;
}

//打开日志文件
static int ITCAST_Error_OpenFile(int* pf)
{
	char	fileName[1024];
	
	memset(fileName, 0, sizeof(fileName));
#ifdef WIN32
	sprintf(fileName, "c:\\itcast\\%s",ITCAST_DEBUG_FILE_);
#else
	sprintf(fileName, "%s/log/%s", getenv("HOME"), ITCAST_DEBUG_FILE_);
#endif
    
    *pf = open(fileName, O_WRONLY|O_CREAT|O_APPEND, 0666); //?
    if(*pf < 0)
    {
        return -1;
    }
	
	return 0;
}
//日志核心部分
static void ITCAST_Error_Core(const char *file, int line, int level, int status, const char *fmt, va_list args)
{
    char str[ITCAST_MAX_STRING_LEN]; //日志内容
    int	 strLen = 0;       //记录日志记录拼接中临时长度变量
    char tmpStr[64];       //记录日志时间
    int	 tmpStrLen = 0;    //记录日志记录拼接中临时内容变量
    int  pf = 0;
    
    //初始化
    memset(str, 0, ITCAST_MAX_STRING_LEN); //重置日志内容内存
    memset(tmpStr, 0, 64);
    
    //加入LOG时间
    tmpStrLen = ITCAST_Error_GetCurTime(tmpStr); //获取系统当前时间
    tmpStrLen = sprintf(str, "[%s] ", tmpStr);//将tempStr日期按格式[]写入str中
    strLen = tmpStrLen;           //接收返回日期时间的长度

    //加入LOG等级
    tmpStrLen = sprintf(str+strLen, "[%s] ", ICLevelName[level]);
    strLen += tmpStrLen;
    
    //加入LOG状态
    if (status != 0) 
    {
        tmpStrLen = sprintf(str+strLen, "[ERRNO is %d] ", status);
    }
    else
    {
    	tmpStrLen = sprintf(str+strLen, "[SUCCESS] ");
    }
    strLen += tmpStrLen;

    //加入LOG信息
    tmpStrLen = vsprintf(str+strLen, fmt, args);
    strLen += tmpStrLen;

    //加入LOG发生文件
    tmpStrLen = sprintf(str+strLen, " [%s]", file);
    strLen += tmpStrLen;

    //加入LOG发生行数
    tmpStrLen = sprintf(str+strLen, " [%d]\n", line);
    strLen += tmpStrLen;
    
    //打开LOG文件
    if(ITCAST_Error_OpenFile(&pf))
	{
		return ;
	}
	
    //写入LOG文件
    write(pf, str, strLen);
    //IC_Log_Error_WriteFile(str);
    
    //关闭文件
    close(pf);
    
    return ;
}


void ITCAST_LOG(const char *file, int line, int level, int status, const char *fmt, ...)
{
    va_list args;
	
	//判断是否需要写LOG
//	if(level!=IC_DEBUG_LEVEL && level!=IC_INFO_LEVEL && level!=IC_WARNING_LEVEL && level!=IC_ERROR_LEVEL)
	if(level == IC_NO_LOG_LEVEL)
	{
		return ;
	}
	
	//调用核心的写LOG函数
    va_start(args, fmt);
    ITCAST_Error_Core(file, line, level, status, fmt, args);
    va_end(args);
    
    return ;
}

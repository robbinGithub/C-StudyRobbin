#include <sys/types.h>  //��Unix/Linuxϵͳ�Ļ���ϵͳ�������͵�ͷ�ļ�
#include <sys/stat.h>   //��ȡ�ļ�����
#include <fcntl.h>      //�������ļ����������õ�����غ��open,fcntl����ԭ��
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ItcastLog.h"

#define ITCAST_DEBUG_FILE_	"socketclient.log" //��־�ļ���
#define ITCAST_MAX_STRING_LEN 		10240      //��־����

//Level���
#define IC_NO_LOG_LEVEL			0
#define IC_DEBUG_LEVEL			1
#define IC_INFO_LEVEL			2
#define IC_WARNING_LEVEL		3
#define IC_ERROR_LEVEL			4

//Level����
int  LogLevel[5] = {IC_NO_LOG_LEVEL, IC_DEBUG_LEVEL, IC_INFO_LEVEL, IC_WARNING_LEVEL, IC_ERROR_LEVEL};

//Level������
char ICLevelName[5][10] = {"NOLOG", "DEBUG", "INFO", "WARNING", "ERROR"};

//��static�ڲ�����
static int ITCAST_Error_GetCurTime(char* strTime)
{
	struct tm*		tmTime = NULL;
	size_t			timeLen = 0;
	time_t			tTime = 0;	
	
	tTime = time(NULL);        //����time.h��ȡʱ��ṹ��ָ��
	tmTime = localtime(&tTime);//ת��ʱ��Ϊstr����
	//timeLen = strftime(strTime, 33, "%Y(Y)%m(M)%d(D)%H(H)%M(M)%S(S)", tmTime);
	timeLen = strftime(strTime, 33, "%Y.%m.%d %H:%M:%S", tmTime);//��ȡʱ�䳤��
	return timeLen;
}

//����־�ļ�
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
//��־���Ĳ���
static void ITCAST_Error_Core(const char *file, int line, int level, int status, const char *fmt, va_list args)
{
    char str[ITCAST_MAX_STRING_LEN]; //��־����
    int	 strLen = 0;       //��¼��־��¼ƴ������ʱ���ȱ���
    char tmpStr[64];       //��¼��־ʱ��
    int	 tmpStrLen = 0;    //��¼��־��¼ƴ������ʱ���ݱ���
    int  pf = 0;
    
    //��ʼ��
    memset(str, 0, ITCAST_MAX_STRING_LEN); //������־�����ڴ�
    memset(tmpStr, 0, 64);
    
    //����LOGʱ��
    tmpStrLen = ITCAST_Error_GetCurTime(tmpStr); //��ȡϵͳ��ǰʱ��
    tmpStrLen = sprintf(str, "[%s] ", tmpStr);//��tempStr���ڰ���ʽ[]д��str��
    strLen = tmpStrLen;           //���շ�������ʱ��ĳ���

    //����LOG�ȼ�
    tmpStrLen = sprintf(str+strLen, "[%s] ", ICLevelName[level]);
    strLen += tmpStrLen;
    
    //����LOG״̬
    if (status != 0) 
    {
        tmpStrLen = sprintf(str+strLen, "[ERRNO is %d] ", status);
    }
    else
    {
    	tmpStrLen = sprintf(str+strLen, "[SUCCESS] ");
    }
    strLen += tmpStrLen;

    //����LOG��Ϣ
    tmpStrLen = vsprintf(str+strLen, fmt, args);
    strLen += tmpStrLen;

    //����LOG�����ļ�
    tmpStrLen = sprintf(str+strLen, " [%s]", file);
    strLen += tmpStrLen;

    //����LOG��������
    tmpStrLen = sprintf(str+strLen, " [%d]\n", line);
    strLen += tmpStrLen;
    
    //��LOG�ļ�
    if(ITCAST_Error_OpenFile(&pf))
	{
		return ;
	}
	
    //д��LOG�ļ�
    write(pf, str, strLen);
    //IC_Log_Error_WriteFile(str);
    
    //�ر��ļ�
    close(pf);
    
    return ;
}


void ITCAST_LOG(const char *file, int line, int level, int status, const char *fmt, ...)
{
    va_list args;
	
	//�ж��Ƿ���ҪдLOG
//	if(level!=IC_DEBUG_LEVEL && level!=IC_INFO_LEVEL && level!=IC_WARNING_LEVEL && level!=IC_ERROR_LEVEL)
	if(level == IC_NO_LOG_LEVEL)
	{
		return ;
	}
	
	//���ú��ĵ�дLOG����
    va_start(args, fmt);
    ITCAST_Error_Core(file, line, level, status, fmt, args);
    va_end(args);
    
    return ;
}

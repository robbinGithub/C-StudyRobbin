
// myop.h

#ifndef _MYOP_H_
#define _MYOP_H_

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct _Teacher
{
	int id;
	char name[64];
	int age ;
	char stuinfo[1024];
}Teacher;

int AddTeacher(char *pFileName, Teacher *pT);
int ShowTeacher(char *pFileName, Teacher *pT);

#ifdef  __cplusplus //_MYOP_H_
}
#endif

#endif 

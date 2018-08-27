#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "cfg_op.h"
#include "myop.h"


#define  DB_sid			"oracle_sid"
#define  DB_User		"appuser"
#define  DB_PassWord	"appuser"
#define	 CFG_FILENAME	"c:/cfg.ini"

void main_menu()
{
	printf("\n1 Test AddTeacher(测试添加老师信息)	");
	printf("\n2 Test ShowTeaqcher(测试显示老师)	");
	printf("\n0 exit(0)        (程序退出)	    ");
	printf("\nplease enter your choice:[1/2/0]: ");
	return;
}


int  Test_AddTeacher()
{
	int ret = 0;

	char *pFileName = "c:/teacherinfo.ini";

	Teacher t;
	t.id = 1;
	strcpy(t.name, "ddd");
	t.age = 32;
	strcpy(t.stuinfo, "s1,s2,s3,");
	
	ret = AddTeacher(pFileName, &t);
	if (ret != 0)
	{
		printf("func AddTeacher() err:%d", ret);
		return ret;
	}
	return ret;
}

int  Test_ShowTeaqcher()
{
	return 0;
	
}
int  main()
{
	int		rv = 0; 
	int		choice = 0;

	for(;;)
	{
		main_menu();
	    scanf("%d", &choice);
        switch (choice)
		{
		case 1:
			Test_AddTeacher();   break;
		case 2:
			Test_ShowTeaqcher();   break;
		case 0:
			exit(0);
		default:
			exit(0);
		}
	}

End:
	return rv;
	getchar();
}



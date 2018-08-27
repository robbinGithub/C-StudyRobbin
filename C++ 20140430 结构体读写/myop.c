#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "myop.h"
#include "cfg_op.h"

//�����ʦ
int AddTeacher(char *pFileName, Teacher *pT)
{   //����������
	int ret;
	//�����������
	char Teacher_InfoID[256] = {0};
	char Teacher_Name[256] = {0};
	char Teacher_Age[256] = {0};
	char Teacher_StudentInfo[256] = {0};
	char tmpId[128] = {0};
	char tmpAge[128] = {0};

    //������123 ��ӡ��һ���ַ���������s �� sprintf(s, "%d", 123); //����"123"

	sprintf(Teacher_InfoID, "%s%d", "Teacher_InfoID_", pT->id);
	sprintf(Teacher_Name, "%s%d", "Teacher_Name_", pT->id);
	sprintf(Teacher_Age, "%s%d", "Teacher_Age_", pT->id);
	sprintf(Teacher_StudentInfo, "%s%d", "Teacher_StudentInfo_", pT->id);

	sprintf(tmpId, "%d", pT->id);
	sprintf(tmpAge, "%d", pT->age);

	ret = SetCfgItem(pFileName /*in*/,Teacher_InfoID /*in*/, tmpId /*in*/, strlen(tmpId) /*in*/);
	if (ret != 0)
	{
		printf("in AddTeacher(), call SetCfgItem() err:%d tmpId:%d", ret, tmpId);
		return ret;
	}
	ret = SetCfgItem(pFileName /*in*/,Teacher_Name /*in*/, pT->name /*in*/, strlen(pT->name) /*in*/);
	if (ret != 0)
	{
		printf("in AddTeacher(), call SetCfgItem() err:%d ", ret);
		return ret;
	}
	ret = SetCfgItem(pFileName /*in*/,Teacher_Age /*in*/, tmpAge /*in*/, strlen(tmpAge) /*in*/);
	if (ret != 0)
	{
		printf("in AddTeacher(), call SetCfgItem() err:%d ", ret);
		return ret;
	}
	ret = SetCfgItem(pFileName /*in*/,Teacher_StudentInfo /*in*/, pT->stuinfo /*in*/, strlen(pT->stuinfo) /*in*/);
	if (ret != 0)
	{
		printf("in AddTeacher(), call SetCfgItem() err:%d ", ret);
		return ret;
	}
	return 0;
}
int ShowTeacher(char *pFileName, Teacher *pT)
{
	return 0;
}

void mainxxx()
{
	system("pause");
}
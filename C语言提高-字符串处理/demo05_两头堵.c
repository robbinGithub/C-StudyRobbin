#include "stdlib.h"
#include "stdio.h"
#include "string.h"


void main_051(){
	int ret = 0;
	char instr[] = "  rwe  ";
	char outstr[200];
	ret = trimSpace(instr, outstr);
	if (ret != 0){
		printf("func trimSpace err:\d\n", ret);
		return;
	}
	printf("str:%s", outstr);
	system("pause");

}

//一般情况下不要修改输入的内存块的值
int trimSpace_ok(char *mybuf, char *outbuf)
{
	int count = 0;
	int i = 0, j = 0;

	char *p = mybuf;
	j = strlen(p) - 1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j]) && j>0)
	{
		j--;
	}
	count = j - i + 1;

	//
	printf("count:%d", count);
	//void *  __cdecl memcpy(void *, const void *, size_t);
	memcpy(outbuf, mybuf + i, count);
	outbuf[count] = '\0';
	return 0;
	//system("pause");
}

int trimSpace(char *mybuf, char*outbuf){
	char *p = mybuf;
	int count = 0;
	int i = 0 ,j=0;
    j = strlen(p)-1;
	while (isspace(p[i]) && p[i] != '\0'){
		i++;
		
	}
	while (isspace(p[j]) &&j>0){
		j--;
	}
	count = j - i + 1;
	memcpy(outbuf, mybuf+i, count);
	outbuf[count] = '\0';
	return 0;
}



/*int trimSpace2(char *instr, char*outstr){
int count = 0;
int start = 0;
int end = 0;
while (isspace(*instr) && *instr != "\0"){
start++;
instr++;
}
while (isspace(*outstr)){
end++;
outstr--;
}
count = end - start + 1;
memcpy(outstr, instr+start, count);
return 1;
}*/


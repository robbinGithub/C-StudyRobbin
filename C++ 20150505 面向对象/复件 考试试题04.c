#include "stdlib.h"
#include "stdio.h"
#include "string.h"

//Ë³Ðò´æ´¢ É¾³ý
int delAlp(char *p, int pos)
{
	int i = 0, len = 0;

	if (p == NULL)
	{
		return -1;
	}
	len = strlen(p);

	for (i=pos; i<len; i++)
	{
		p[i-1] = p[i];
	}
	p[len-1] = '\0';
	return 0;
}
void main0004()
{
	int ret = 0;
	char buf[] = "hellokityManGood";

	ret = delAlp(buf, 3);
	if (ret != 0)
	{
		return ;
	}
	printf("%s\n", buf);
	ret = delAlp(buf, 6);
	if (ret != 0)
	{
		return ;
	}
	printf("%s\n", buf);
	ret = delAlp(buf, 9);
	if (ret != 0)
	{
		return ;
	}
	printf("%s\n", buf);

	system("pause");
}
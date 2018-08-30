#include "stdlib.h"
#include "stdio.h"
#include "string.h"


int  main2(){
	char c;
	char str[] = "robbin";
	int len = strlen(str);
	char * p1  = str;
	char *p2 = p1 + len - 1;
	while (p1 < p2){
		c = *p1;
		*p1 = *p2;
		*p2 = c;
		p1++;
		p2--;
	}
	printf("str:%s", str);
	system("pause");
	return 0;
}



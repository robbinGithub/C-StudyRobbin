#include <stdlib.h>
#include<stdio.h>
#include<string.h>
void main(){
	char *sub = "abcd";
	int count = 0;
	char *p = "abcd135435435435435abcd";
	do{
		p = strstr(p, sub);
		if (p != NULL){
			count++;
			p = p + strlen(sub);
		}
		else{
			break;
		}

	} while (*p != '\0');
	printf("count:%d", count);
	system("pause");

}


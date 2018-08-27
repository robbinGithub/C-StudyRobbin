#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <windows.h> 

int  str_copy1(char * from, char*to){
	int ret = 0;
	if (from == NULL || to == NULL){
	
		printf("func copy_str1():%d,(from==NULL||to==NULL", ret);

		return ret;
	}
	for (; *from != '\0'; from++,to++){
		*to = *from;
	}
	*to = '\0';
	return ret;
}
void str_copy3(char *from,char*to){
	while (*from != '\0'){
		*to++ = *from++;  //后缀++优先级高于*p
	}

}
void str_copy4(char *from, char*to){
	while ((*to++ = *from++)!= '\0'){
		;  //后缀++优先级高于*p
	}
}
void main2(){
	char from[100] = { 0 };
	char to[100] = { 0 };
	strcpy(from, "abcd");
	printf("%s", from);
	str_copy1(from, to); 
	printf("%s", to);
	system("pause");
}

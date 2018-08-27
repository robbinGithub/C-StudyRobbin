#include <stdio.h>
#include <stdlib.h>

int main_E0()
{
	FILE * fp_pic, *fp_file, *fp_finish;
	char ch, fp_pic_name[20], fp_file_name[20], fp_finish_name[20];
	
	printf("请输入需要合成的图片和文件名称：\n");
	printf("图片：");
	scanf("%s", fp_pic_name);
	printf("文件：");
	scanf("%s", fp_file_name);
	printf("生成为：");
	scanf("%s", fp_finish_name);

	if (!(fp_pic = fopen(fp_pic_name, "rb+")))
	{
		printf("Cannot open the picture %s !", fp_pic_name);
		return;
	}

	if (!(fp_file = fopen(fp_file_name, "rb+")))
	{
		printf("Cannot open the picture %s !", fp_file_name);
		return;
	}

	if (!(fp_finish = fopen(fp_finish_name, "wb+")))
	{
		printf("Cannot open the picture %s !", fp_finish_name);
		return;
	}

	while (!feof(fp_pic)){
		ch = fgetc(fp_pic);
		fputc(ch, fp_finish);
	}
	fclose(fp_pic);

	while (!feof(fp_file)){
		ch = fgetc(fp_file);
		fputc(ch, fp_finish);
	}

	fclose(fp_file);
	fclose(fp_finish);
	  
	system("pause");
	return 0;
}

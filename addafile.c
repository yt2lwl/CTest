/*************************************************************************
	> File Name: addafile.c
	> Author: 
	> Mail: 
	> Created Time: 2016年06月21日 星期二 01时35分35秒
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp=fopen("test.txt","w");
    fprintf(fp,"%d\n%s",137,"haahahhahah");
    fclose(fp);
    return 0;
}

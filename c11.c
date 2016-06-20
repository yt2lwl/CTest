/*************************************************************************
	> File Name: c11.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月10日 星期四 00时05分43秒
 ************************************************************************/

#include<stdio.h>
int main(void)
{
    #ifdef __STDC_LIB_EXT1__
    printf("c++11 supported!\n");
    #else
    printf("c++11 not supported!\n");
    //printf_s("testc11\n");
    #endif
    return 0;
}

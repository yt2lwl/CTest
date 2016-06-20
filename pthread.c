/*************************************************************************
	> File Name: thread.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月10日 星期四 12时56分42秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct MyData
{
    pthread_t id;
    int a;
    int b;
}MyData;

//Get data function
int get_data(void *pdata)
{
    MyData *pd = (MyData*)pdata;
    printf("The get_data thread received:data.a=%d and data.b=%d\n",
           pd->a,pd->b);
    int mult = 0;
    printf("Enter an integer multiplier:\n");
    scanf("%d", &mult);
    pd->a *= mult;
    printf("The get_data thread makes it:data.a=%d and data.b=%d\n",
          pd->a, pd->b);
    return 0;
}

//Process data function
int process_data(void *pdata)
{
    MyData *pd = (MyData*)pdata;
    int *result = NULL;
    if(pthread_join(pd->id, &result))
    {
        fprintf(stderr,"get_data thread join by process_data failed!\n");
        pthread_exit(-1);
    }
    if(-1 == result)
    {
        fprintf(stderr,"process_data thread readind data failed!\n");
        pthread_exit(2);
    }
    printf("The process_data thread received:data.a=%d and data.b=%d\n ",
          pd->a, pd->b);
    pthread_exit(0);
}

int main(void)
{
    pthread_t process_id;
    MyData mydata={ .a = 123, .b=345};
    printf("Before:data.a=%d and data.b=%d\n", mydata.a, mydata.b);
    if(!pthread_create(&mydata.id, NULL, get_data, &mydata))
    {
        printf("get_data thread started!\n");
    }
    else
    {    
        fprintf(stderr, "Failed to start get_data thread!\n");
        exit(1);
    }
    if(!pthread_create(&process_id, NULL, process_data, &mydata))
    {
        printf("process_data thread started!\n");
    }
    else
    {    
        fprintf(stderr, "Failed to start process_data thread!\n");
        exit(1);
    }
    pthread_join(process_id, NULL);
    printf("After both threads finish executing:data.a=%d and data.b=%d\n",
          mydata.a,mydata.b);
    return 0;
}

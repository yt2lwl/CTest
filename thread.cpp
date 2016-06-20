/*************************************************************************
	> File Name: thread.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月22日 星期五 10时55分46秒
 ************************************************************************/

#include<iostream>
#include<thread>
using namespace std;
int main(int argc, char *argv[])
{
    thread t(printf, "Hello,t1");
    thread t1(printf, "Hello,t2");
    t.join();
    t1.join();
    return 0;
}

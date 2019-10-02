#include<bits/stdc++.h>
using namespace std;
int main()
{
    system("g++ c.cpp -std=c++11 -o c -O2");
    system("g++ a.cpp -std=c++11 -o a -O2");
    system("g++ b.cpp -std=c++11 -o b -O2");
    for(int i=1;i;i++)
    {
        printf("running on test %d\n",i);
        system("c>in");
        system("a<in>out");
        system("b<in>ans");
        if(system("fc ans out > nul"))
        {
            puts("WA");
            break;
        }
        else puts("AC");
    }
    return 0;
}
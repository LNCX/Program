#include<bits/stdc++.h>
using namespace std;
string s[5]={"ooo.ooo.ooo.ooo","**o.o*o.*o*.o*o","ooo.o*o.*o*.ooo","o**.o*o.*o*.o*o","ooo.ooo.ooo.ooo"};
int main()
{
    int n;
    scanf("%d",&n);
    for(int k=0;k<=5;k++)
    {
        for(auto i:s[k])
        {
            if(i=='*') putchar('.');
            else if(i=='.') for(int j=1;j<=n;j++) putchar('.');
            else putchar(i);
        }
        puts("");
    }
    return 0;
}
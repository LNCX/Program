#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,t=0;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
       d=a+b+c;
       if( t>0) printf("\n");//如果前面已经有过输出了,这次要先输出一个空行
       printf("%d\n",d);//注意后面的\n
       t++;

    }
}


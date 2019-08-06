#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int N=2e4;
char s[10];
int c[N+5],x,y;
void add(int x,int y)
{
    while(x<=N)
    {
        c[x]^=y;
        x+=lowbit(x);
    }
}
int ask(int x)
{
    int res=0;
    while(x>0)
    {
        res^=c[x];
        x-=lowbit(x);
    }
    return res;
}
int main()
{
    while(~scanf("%s",s))
    {
        if(*s=='A'||*s=='R')
        {
            scanf("%d",&x);
            add(x,x);
        }
        else
        {
            scanf("%s%d%s%d",s,&x,s,&y);
            if(x>y) puts("0");
            else printf("%d\n",ask(y)^ask(x-1));
        }
    }
    return 0;   
}
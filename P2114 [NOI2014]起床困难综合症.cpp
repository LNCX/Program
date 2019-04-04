#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,ans=0;
    int a1=0,a2=-1;
    scanf("%d%d",&n,&m);
    while(n--)
    {
        int x;
        char s[5];
        scanf("%s%d",s,&x);
        if(s[0]=='A') a1&=x, a2&=x;
        if(s[0]=='X') a1^=x, a2^=x;
        if(s[0]=='O') a1|=x, a2|=x;
    }
    for(int j=29;j!=-1;j--)
    {
        if(a1>>j&1) 
            ans+=1<<j;
        else if(a2>>j&1&&(1<<j)<=m) 
        {
            ans+=1<<j;
            m-=1<<j;
        }
    }
    printf("%d\n",ans);
    return 0;
}
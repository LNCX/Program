#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
char s[N];
int f[N],ans,n;
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)
    {
        int w=0;
        for(int j=i;j<=n&&!((1<<s[j]-'a')&w);j++)
        {
            w|=(1<<(s[j]-'a'));
            f[w]=max(f[w],j-i+1);
        }
    }
    for(int i=0;i<(1<<20);i++)
        for(int j=0;j<20;j++)
            if((1<<j)&i)
            {
                f[i]=max(f[i],f[i^(1<<j)]);
            }
    for(int i=0;i<(1<<20);i++)
        ans=max(ans,f[i]+f[((1<<20)-1)^i]);
    printf("%d\n",ans);
    return 0;
}
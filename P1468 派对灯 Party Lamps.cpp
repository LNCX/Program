#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10;
int n,t,s[maxn],a[20][maxn],cnt,op[maxn];
int main()
{
    int tmp;
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++)
    s[i]=-1;
    while(1)
    {
        scanf("%d",&tmp);
        if(tmp==-1)break;
        s[tmp]=1;
    }
    while(1)
    {
        scanf("%d",&tmp);
        if(tmp==-1)break;
        s[tmp]=0;
    }
    for(int i=0;i<=1;i++)
        for(int j=0;j<=1;j++)
            for(int k=0;k<=1;k++)
                for(int l=0;l<=1;l++)
                {
                    if((i+j+k+l)%2==t%2&&i+j+k+l<=t)
                    {
                        cnt++;
                        for(int t=1;t<=n;t++)
                            a[cnt][t]=1;
                        for(int t=1;t<=n&&i;t++)
                            a[cnt][t]=1-a[cnt][t];
                        if(j)
                            for(int t=1;t<=n&&j;t+=2)
                                a[cnt][t]=1-a[cnt][t];
                        for(int t=2;t<=n&&k;t+=2)
                            a[cnt][t]=1-a[cnt][t];
                        for(int t=1;t<=n&&l;t+=3)
                            a[cnt][t]=1-a[cnt][t];
                        for(int t=1;t<=n;t++)
                        {
                            if((a[cnt][t]==s[t])||(a[cnt][t]==s[t])||s[t]==-1);
                            else
                            {
                                cnt--;
                                break;
                            }
                        }
                    }
                }
    if(cnt==0)
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for(int ca=1;ca<=n;ca++)
        for(int i=1;i<=cnt-1;i++)
            for(int j=1;j<=cnt-i;j++)
                for(int k=1;k<=n;k++)
                {
                    if(a[j][k]==a[j+1][k])
                        continue;
                    else if(a[j][k]<a[j+1][k])break;
                    else
                    {
                        swap(a[j],a[j+1]);
                        break;
                    }
                }
    for(int i=1;i<=cnt;i++,cout<<endl)
        for(int j=1;j<=n;j++)
            printf("%d",a[i][j]);
    return 0;
}
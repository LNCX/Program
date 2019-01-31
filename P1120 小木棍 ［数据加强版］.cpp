#include<bits/stdc++.h>
using namespace std;
int n;
int a[70];
int sum,m,Max,len;
bool visit[70];
void dfs(int k,int last,int rest)
{
    if(k==m)
    {
        printf("%d",len);
        exit(0);
    }
    if(rest==0)
    {
        int flag=n+1;
        for(int i=1;i<=n;i++)
        {
            if(!visit[i])
            {
                visit[i]=1;
                flag=i;
                break;
            }
        }
        dfs(k+1,flag,len-a[flag]);
        visit[flag]=0;
    }
    else
    {
        for(int i=last+1;i<=n;i++)
        {
            if(!visit[i]&&rest>=a[i])
            {
                visit[i]=1;
                dfs(k,i,rest-a[i]);
                visit[i]=0;
                int j=i;
                while(i<n&&a[i]==a[j]) i++;
            }
        }
    }
}
inline bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        Max=max(Max,a[i]);
        sum+=a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=Max;i<=sum;i++)
    {
        if(sum%i==0)
        {
            m=sum/i;
            len=i;
            memset(visit,0,sizeof(visit));
            visit[1]=1;
            dfs(1,1,len-a[1]);
        }
    }
    return 0;
}

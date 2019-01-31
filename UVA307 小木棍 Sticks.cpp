#include<bits/stdc++.h>
using namespace std;
int n,len=0,top=0,all=0; 
bool vis[105],flag=0;
int b[105];
struct gun
{
    int num,l; 
}a[105];
bool cmp(gun x,gun y)
{
    return x.l>y.l; 
}
void dfs(int num,int last,int tot)
{
    if(flag) return;
    if(tot==len)
    {
        tot=0;
        last=1;
    }
    if(num==all)
    {
        if(tot==0)
        {
            printf("%d\n",len);
            flag=1;
            return ;
        }
        else return;
    }
    for(int i=last;i<=top;i++)
    {
        if(a[i].num&&tot+a[i].l<=len)
        {
            a[i].num--;
            dfs(num+1,i,tot+a[i].l);
            a[i].num++;len=0,top=0,all=0;
            if(tot==0||tot+a[i].l==len)
            	break;
        }
    }
}
void clear()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(vis,0,sizeof(vis));
    len=0,top=0,all=0,flag=0;
}
int main()
{
    while(scanf("%d",&n))
    {
        if(n==0) return 0;
        int sum=0,maxn=0;
        clear();
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if(x<=50)
            {
                b[x]++;
                maxn=max(x,maxn);
                sum+=x;
                all++;
            }
        }
        for(int i=1;i<=50;i++)
            if(b[i])
            {
                a[++top].l=i;
                a[top].num=b[i];
            }
        sort(a+1,a+top+1,cmp);
        for(len=maxn;len<=sum/2;len++)
            if (sum%len==0)
                dfs(0,1,0);
    }
}

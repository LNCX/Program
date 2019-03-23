#include<bits/stdc++.h>
using namespace std;
bool a[65];
bool check(int id,int x)
{
    if(!a[id]) x=-x;
    return x==1?true:false;
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",1);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        if(x==0) exit(0);
        else if(x==-1) a[i]=false;
        else a[i]=true;
    }
    int l=1,r=m,cnt=0;
    while(l<r)
    {
        int mid=(l+r)>>1;
        printf("%d\n",mid);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        if(x==0) exit(0);
        if(check(++cnt,x))
            l=mid+1;
        else r=mid-1;
        if(cnt==n) cnt=0;
    }
    printf("%d\n",l);
    exit(0);
}
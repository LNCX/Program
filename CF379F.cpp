#include<cstdio>
#include<iostream>
const int maxn=1e6+100;
int f[maxn][22],dep[maxn];
int n=4,q,a,b,r;
int dis(int x,int y)
{
    int len=dep[x]+dep[y];
    if(dep[x]<dep[y]) std::swap(x,y);
    for(int i=20;i>=0&&dep[x]!=dep[y];i--)
    {
        if(dep[f[x][i]]>=dep[y])
            x=f[x][i];
    }
    if(x==y) return len-(dep[x]<<1);
    for(int i=20;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    x=f[x][0];
    return len-(dep[x]<<1);
}
int main()
{
    scanf("%d",&q);
    f[2][0]=f[3][0]=f[4][0]=dep[1]=1;
    dep[2]=dep[3]=dep[4]=2;
    a=2,b=4;r=2;
    while(q--)
    {
        int x=++n,y=++n;
        scanf("%d",&f[x][0]);
        f[y][0]=f[x][0];
        dep[x]=dep[y]=dep[f[x][0]]+1;
        for(int i=1;i<=20;i++)
            f[y][i]=f[x][i]=f[f[x][i-1]][i-1];
        int r1=dis(a,x),r2=dis(b,x);
        if(r1>r) r=r1,b=x;
        if(r2>r) r=r2,a=x;
        printf("%d\n",r);
    }
    return 0;
}
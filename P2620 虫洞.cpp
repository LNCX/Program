#include<bits/stdc++.h>
using namespace std; 
int l[100],c,x[50],y[50],d[100][100],w,s,p;
set<int>se;
int F(int b,int e)
{
    if(b==e)
        return 0;
    if(se.count(b))
        return 0x3fffffff;
    int f=e;
    for(int i=0;i<p;i++)
    {
        if(b<x[i]&&x[i]<f&&(x[i]-b)%s==0)
            f=x[i];
    }
    while(f!=e&&se.count(f))
        f--;
    if(f==b)
        return 0x3fffffff;
    return (f-b+s-1)/s+F(f,e);
}
int cal(int x)
{
    return lower_bound(l,l+c,x)-l;
}
int main()
{
    while(scanf("%d%d%d",&w,&s,&p),w)
    {
        se.clear();
        c=0;
        for(int i=0;i<p;i++)
        {
            scanf("%d %d",x+i,y+i);
            se.insert(x[i]);
            l[c++]=x[i],l[c++]=y[i];
        }
        l[c++]=0,l[c++]=w;
        sort(l,l+c);
        c=unique(l,l+c)-l;
        memset(d,0x3f,sizeof d);
        for(int i=0;i<p;i++)
            d[cal(x[i])][cal(y[i])]=0;
        for(int i=0;i<c;i++)
            for(int j=i+1;j<c;j++)
                d[i][j]=min(d[i][j],F(l[i],l[j]));
        for(int k=0;k<c;k++)
            for(int i=0;i<c;i++)
                for(int j=0;j<c;j++)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        printf("%d\n",d[0][c-1]);
    }
    return 0;
}
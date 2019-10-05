#include<bits/stdc++.h>
const int N=(1<<17)+5;
int n,m,b[N<<2],c[N<<2];
inline int read(){int x;scanf("%d",&x);return x;}
void fix(int x,int y,int k=1,int l=1,int r=1<<n)
{
    if(l==r) return void(c[k]=y);
    int mid=(l+r)>>1;
    x<=mid?fix(x,y,k<<1,l,mid):fix(x,y,k<<1|1,mid+1,r);
    (b[k]=b[k<<1]^1)?c[k]=c[k<<1]|c[k<<1|1]:c[k]=c[k<<1]^c[k<<1|1];
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=(1<<n);i++) fix(i,read());
    for(int i=1;i<=m;i++)
    {
        int x=read(),y=read();
        fix(x,y),printf("%d\n",c[1]);
    }
    return 0;
}
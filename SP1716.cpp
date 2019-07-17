#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,inf=0x3f3f3f3f;
int a[N];
struct mat
{
    int c[4][4];
    friend mat operator*(const mat a,const mat b)
    {
        mat res;
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                res.c[i][j]=-inf;
        for(int k=1;k<=3;k++)
            for(int i=1;i<=3;i++)
                for(int j=1;j<=3;j++)
                    res.c[i][j]=max(a.c[i][k]+b.c[k][j],res.c[i][j]);
        return res;
    }
    void start()
    {
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                c[i][j]=0;
    }
};
mat sum[N<<2];
void pushup(int k){sum[k]=sum[k<<1]*sum[k<<1|1];}
void build(int k,int l,int r)
{
    if(l==r)
    {
        sum[k].c[2][2]=sum[k].c[3][3]=0;
        sum[k].c[1][2]=sum[k].c[3][1]=sum[k].c[3][2]=-inf;
        sum[k].c[1][1]=sum[k].c[1][3]=sum[k].c[2][1]=sum[k].c[2][3]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    pushup(k);
}
void modify(int k,int l,int r,int x,int w)
{
    if(l>x||r<x) return ;
    if(l==r)
    {
        sum[k].c[1][1]=sum[k].c[1][3]=sum[k].c[2][1]=sum[k].c[2][3]=w;
        return ;
    }
    int mid=(l+r)>>1;
    modify(k<<1,l,mid,x,w);
    modify(k<<1|1,mid+1,r,x,w);
    pushup(k);
}
mat query(int k,int l,int r,int x,int y)
{
    if(x<=l&&r<=y){return sum[k];}
    int mid=(l+r)>>1;
    mat res;res.start();
    if(mid>=x) res=res*query(k<<1,l,mid,x,y);
    if(mid< y) res=res*query(k<<1|1,mid+1,r,x,y);
    return res;
}
void print(mat k)
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(k.c[i][j]<-1e9) printf("-inf\t");
            else printf("%d\t",k.c[i][j]);

        }
        puts("");
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    int q;
    cin>>q;
    for(int i=1;i<=7;i++)
        printf("%d\n",i),print(sum[i]),puts(""); 
    while(q--)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op)
        {
            mat k=query(1,1,n,x,y);
            print(k);
            printf("%d\n",max(k.c[2][3],k.c[2][1]));
        }
        else modify(1,1,n,x,y);
    }
}
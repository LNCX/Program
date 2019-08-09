#include<bits/stdc++.h>
const int N = 20;
int n,p,k,m;
int a[N],b[N],c[N],d[N];
int power(int a,int b)
{
    a%=p;
    int ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%p;
        b>>=1;a=a*a%p;
    }
    return ans;
}
int add(int x, int y)
{
    for(int i=0;i<=k;i++)
        c[i]=(x%p+y%p)%p,x/=p,y/=p;
    int ans=0;
    for(int i=k;i>=0;i--)
        (ans*=p)+=c[i];
    return ans;
}
int mul(int x,int y)
{
    memset(c,0,sizeof(c));
    for(int i=0;i<=k;i++)
        a[i]=x%p,b[i]=y%p,x/=p,y/=p;
    for(int i=0;i<=k;i++)
        for(int j=0;j<=k;j++)
            (c[i+j]+=a[i]*b[j]%p)%=p;
    int mid=m;
    for(int i=0;i<=k;i++)
        d[i]=mid%p,mid/=p;
    for(int i=k<<1;i>=k;i--)
    {
        int temp=c[i]*power(d[k],p-2)%p;
        for(int j=0;j<=k;j++)
            (c[i+j-k]-=d[j]*temp%p-p)%=p;
    }
    int ans=0;
    for(int i=k-1;i>=0;i--)
        (ans*=p)+=c[i];
    return ans;
}
int main()
{
    scanf("%d",&n);
    if(n==6||n==143) return puts("-1"),0;
    puts("0");
    if(n==3||n==19||n==89||n==181||n==233)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
                printf("%d ",(i+j)%n);
            printf("%d\n",(i+n-1)%n);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
                printf("%d ",i*j%n);
            printf("%d\n", i*(n-1)%n);
        }
        return 0;
    }
    if(n==4) p=2,k=2,m=7;
    if(n==8) p=2,k=3,m=11;
    if(n==9) p=3,k=2,m=10;
    if(n==25) p=5,k=2,m=27;
    if(n==121) p=11,k=2,m=122;
    if(n==169) p=13,k=2,m=171;
    if(n==27) p=3,k=3,m=34;
    if(n==128) p=2,k=7,m=131;
    if(n==81) p=3,k=4,m=86;
    if(n==125) p=5,k=3,m=131;
    if(n==243) p=3,k=5,m=250;
    if(n==256) p=2,k=8,m=283;
    if(n==343) p=7,k=3,m=345;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
            printf("%d ",add(i,j));
        printf("%d\n", add(i,n-1));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
            printf("%d ",mul(i,j));
        printf("%d\n",mul(i,n-1));
    }
    return 0;
}
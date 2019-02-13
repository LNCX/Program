#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],b[200];
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<=m;i++)
        scanf("%d",&b[i]);
    if(n<m)
    {
        printf("0/1\n");
        return 0;
    }
    if(n>m)
    {
        if(a[0]*b[0]>0)
        {
            printf("Infinity\n");
            return 0;
        }
        else
        {
            printf("-Infinity\n");
            return 0;
        }
    }
    if(a[0]*b[0]<0)
        printf("-");
    int t=gcd(abs(a[0]),abs(b[0]));
    printf("%d/%d\n", abs(a[0])/t,abs(b[0])/t);
    return 0;
}
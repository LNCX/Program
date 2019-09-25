#include<bits/stdc++.h>
using namespace std;
int n;
int a[5],b[5],c[5];
int check(int x,int y)
{
    if(x>=b[1]&&x<=b[2]&&y>=b[3]&&y<=b[4]) return 1;
    if(x>=c[1]&&x<=c[2]&&y>=c[3]&&y<=c[4]) return 1;
    return 0;
}
void judge(int a,int b)
{
    if(!check(a,b))
    {
        exit(0);
        return printf("YES\n");
    }
}
int main()
{
    scanf("%d%d%d%d",&a[1],&a[3],&a[2],&a[4]);
    scanf("%d%d%d%d",&b[1],&b[3],&b[2],&b[4]);
    scanf("%d%d%d%d",&c[1],&c[3],&c[2],&c[4]);
    judge(a[1],a[3]);
    judge(a[2],a[3]);
    judge(a[1],a[4]);
    judge(a[2],a[4]);
    if(b[1]>c[1]) swap(b[1],c[1]),swap(b[2],c[2]);
    if(b[2]>=a[1]&&b[2]<c[1]&&c[1]<=a[2]) return printf("YES\n"),0;
    if(b[3]>c[3]) swap(b[3],c[3]),swap(b[4],c[4]);
    if(b[4]>=a[3]&&b[4]<c[3]&&c[3]<=a[4]) return printf("YES\n"),0;
    printf("NO");
}
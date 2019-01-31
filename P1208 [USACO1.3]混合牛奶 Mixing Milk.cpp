#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    int y;
    bool operator<(const node &n) const
    {
        return this->x<n.x;    
    }
}a[5002];
int main()
{
    int n,m,sum=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+m);
    for(int i=1;i<=m;i++)
    {
        if(n>a[i].y)
        {
            sum+=a[i].x*a[i].y;
            n-=a[i].y;
        }
        else
        {
            sum+=n*a[i].x;
            break;
        }
    }
    printf("%d",sum);
}
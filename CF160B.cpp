#include<bits/stdc++.h>
using namespace std;
int flag=0;
int a[105],b[105];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%1d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%1d",&b[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
    {
        if(a[i]<b[i]&&flag<=0)
            flag=-1;
        else if(a[i]>b[i]&&flag>=0)
            flag=1;
        else
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,x,m,cnt;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(m==x) cnt++;
        if(cnt==0) m=x,cnt++;
        if(m!=x) cnt--;
    }
    printf("%d\n",m);
    return 0;
}
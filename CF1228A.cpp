#include<bits/stdc++.h>
using namespace std;
bool judge(int x)
{
    int a[10]={0};
    while(x)
    {
        a[x%10]++;
        x/=10;
    }
    for(int i=0;i<10;i++)
        if(a[i]>1)
            return false;
    return true;
}
int main()
{
    int l,r;
    scanf("%d%d",&l,&r);
    for(int i=l;i<=r;i++)
        if(judge(i))
        {
            printf("%d\n",i);
            return 0;
        }
    puts("-1");
    return 0;
}

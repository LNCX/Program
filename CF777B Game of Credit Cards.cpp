#include<bits/stdc++.h>
using namespace std;
const int N=1005;
char a[N],b[N];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s%s",a,b);
    sort(a,a+n);sort(b,b+n);
    int i=0,j=0,ans=0;
    while(i<n&&j<n)
    {
        if(b[j]>=a[i]) i++,j++;
        else j++,ans++;
    }
    i=j=0;
    int ans2=0;
    while(i<n&&j<n)
    {
        if(b[j]>a[i])
        {
            i++,j++;
            ans2++;
        } 
        else j++;
    }
    printf("%d\n%d",ans,ans2);
}
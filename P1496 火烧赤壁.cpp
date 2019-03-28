#include<bits/stdc++.h>
using namespace std;
long long a[20001],b[20001],l=0;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
    {
        l+=b[i]-a[i];
        if(i+1<=n&&b[i]>a[i+1])
            l-=b[i]-a[i+1];
    }
    cout<<l<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
string a,b;
int cnt1,cnt2;
int main()
{
    cin>>a>>b;
    for(int i=0;i<a.length();i++)
        if(a[i]=='1')
            cnt1++;
    for(int i=0;i<b.length();i++)
        if(b[i]=='1')
            cnt2++;
    if(cnt1&1) cnt1++;
    if(cnt1<cnt2) puts("NO");
    else puts("YES");
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N];
int n,x,y,ans=0; 
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    scanf("%s",s+1);
    reverse(s+1,s+1+n);
    for(int i=1;i<=y;i++)
        if(s[i]=='1') 
            ans++;
    if(s[y+1]=='0') ans++;
    for(int i=y+2;i<=x;i++)
        if(s[i]=='1')
            ans++;
    cout<<ans<<endl;
    return 0;
}
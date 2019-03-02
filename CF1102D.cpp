#include<bits/stdc++.h>
using namespace std;
string s;
int n,cnt[3];
int main()
{
    cin>>n>>s;
    cnt[0]=cnt[1]=cnt[2]=-n/3;
    for(int i=0;i<n;i++)
        cnt[s[i]-'0']++;
    for(int i=n-1;i>0&&cnt[0]>0;i--) if(s[i]=='0')
    {
        if(cnt[2]<0) s[i]='2',cnt[2]++;
        else s[i]='1',cnt[1]++;
        cnt[0]--;
    }
    for(int i=0;i<n&&cnt[1]>0&&cnt[0]<0;i++) if(s[i]=='1')
    {
        s[i]='0';
        cnt[0]++,cnt[1]--;
    }
    for(int i=n-1;i>0&&cnt[2]<0&&cnt[1]>0;i--) if(s[i]=='1')
    {
        s[i]='2';
        cnt[1]--,cnt[2]++;
    }
    for(int i=0;i<n&&cnt[2]>0;i++) if(s[i]=='2')
    {
        if(cnt[0]<0) s[i]='0',cnt[0]++;
        else s[i]='1',cnt[1]++;
        cnt[2]--;
    }
    cout<<s<<endl;
    return 0;
}
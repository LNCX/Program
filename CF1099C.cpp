#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
char s[200];
int main()
{
    scanf("%s",s);
    int n;
    cin>>n;
    int len=strlen(s);
    int cnt1=0,cnt2=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='?') cnt1++;
        else if(s[i]=='*') cnt2++;
    }
    int l=len-cnt1-cnt2;
    if(l==n)
    {
        for(int i=0;i<len;i++)
        {
            if(s[i]!='?'&&s[i]!='*') cout<<s[i];
        }
        cout<<endl;
    }
    else if(l<n&&cnt2>0)
    {
        int c;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='?') s[i]='#';
            if(s[i]=='*')
            {
                if(l<n)
                {
                    c=n-l;
                    s[i]='!';
                    l=n;
                }
                else s[i]='#';
            }
        }
        for(int i=0;i<len;i++)
        {
            if(s[i]!='#')
            {
                if(s[i]=='!')
                    for(int j=0;j<c;j++)
                        cout<<s[i-1];
                else cout<<s[i];
            }
        }
        cout<<endl;
    }
    else if(l>n&&l-(cnt1+cnt2)<=n)
    {
        for(int i=0;i<len;i++)
        {
            if((s[i]=='?'||s[i]=='*')&&l>n)
            {
                s[i-1]='#';
                s[i]='#';
                l--;
            }
            else if(s[i]=='?'||s[i]=='*')
                s[i]='#';
        }
        for(int i=0;i<len;i++)
        {
            if(s[i]!='#') cout<<s[i];
        }
        cout<<endl;
    }
    else cout<<"Impossible"<<endl;
}
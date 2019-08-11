#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
char s[N];
int a[N];
int main()
{
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='L')
        {
            for(int i=0;i<=9;i++)
                if(a[i]==0)
                {
                    a[i]=1;
                    break;
                }
        }
        else if( s[i]=='R')
        {
            for(int i=9;i>=0;i--)
                if(a[i]==0)
                {
                    a[i]=1;
                    break;
                }
        }
        else a[s[i]-'0']=0;
    }
    for(int i=0;i<=9;i++)
        printf("%d",a[i]);
    puts("");
    return 0;
}
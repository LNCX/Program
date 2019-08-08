#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,ans;
char a[N];
int main()
{
    scanf("%d%s",&n,a+1);
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1])
        {
            ans++;
            char t='R';
            if(a[i-1]=='R'||a[i+1]=='R')
            {
                t='G';
                if(a[i-1]=='G'||a[i+1]=='G')
                    t='B';
            }
            a[i]=t;
        }
    }
    printf("%d\n%s\n",ans,a+1);
}
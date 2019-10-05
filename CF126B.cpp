#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int nxt[N],n,maxx;
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1,j=0;i<=n;i++)
    {
        while(s[i+1]!=s[j+1]&&j>0) j=nxt[j];
        if(s[i+1]==s[j+1]) j++;
        nxt[i+1]=j;
        if(i+1!=n) maxx=max(maxx,nxt[i+1]);
    }
    int x=nxt[n];
    while(x>maxx) x=nxt[x];
    if(!x)puts("Just a legend");
    else for(int i=1;i<=x;i++) printf("%c",s[i]);
    return 0;
}
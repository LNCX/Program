#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll c[N],t[N];
inline ll read()
{
    ll x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-')f=0;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c-'0');c=getchar();}
    return f?x:-x;
}
int main()
{
    int n=read();
    for(int i=1;i<=n;i++)
        c[i]=read();
    for(int i=1;i<=n;i++)
        t[i]=read();
    if(c[1]!=t[1]) return puts("No"),0;
    for(int i=1;i<n;i++)
    {
        c[i]=c[i+1]-c[i];
        t[i]=t[i+1]-t[i];
    }
    sort(c+1,c+1+n);
    sort(t+1,t+1+n);
    for(int i=1;i<=n;i++)
        if(c[i]!=t[i]) 
            return puts("No"),0;
    puts("Yes");
    return 0;
}
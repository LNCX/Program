#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,n,ans;
const int BUFSIZE=1<<20;
char ibuf[BUFSIZE],*is=ibuf,*it=ibuf;
inline char getch()
{
    if(is == it)
        it=(is=ibuf)+fread(ibuf,1,BUFSIZE,stdin);
    return is==it?EOF:*is++;
}
inline ll read()
{
    ll res=0,neg=0,ch=getch();
    while(!(isdigit(ch)||ch=='-')&&ch!=EOF)
        ch=getch();
    if(ch=='-') neg=1,ch=getch();
    while(isdigit(ch))
        res=res*10+(ch-'0'),ch=getch();
    return neg?-res:res;
}
int main()
{
    n=read();
    while(n--)
    {
        x=read();
        ans^=x;
    }
    printf("%d\n",ans);
}
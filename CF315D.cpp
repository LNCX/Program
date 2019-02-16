#include<bits/stdc++.h>
using namespace std;
string a,b;
int n,m,f[150],nxt[150],ans=0,pos=0;
int main()
{
    scanf("%d%d",&n,&m);
    cin>>a>>b;
    int lena=a.length(),lenb=b.length();
    for(int i=0;i<lenb;i++)
    {
        int pos=i;
        for(int j=0;j<lena;j++)
        {
            if(a[j]==b[pos]) pos++;
            if(pos==lenb)f[i]++,pos=0;
        }
        nxt[i]=pos;
    }
    for(int i=0;i<n;i++)
    {
        ans+=f[pos];
        pos=nxt[pos];
    }
    printf("%d\n",ans/m);
}
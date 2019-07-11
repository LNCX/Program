#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f,maxn=5e5+5;
int n,m;
int l[maxn],r[maxn];
multiset<int>s1,s2;
map<int,int>ma;
priority_queue< int,vector<int>,greater<int> > q;
inline int read()
{
    int x=0;
    bool f=true;
    char c=getchar();
    while(!isdigit(c))
    {
        if(c=='-') f=false;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return f?x:-x;
}
void insert(int x)
{
    ma[x]++;
    if(ma[x]==1)
        s1.insert(x);
}
void push(int x)
{
    int l=*--s2.lower_bound(x),r=*s2.lower_bound(x);
    q.push(min(x-l,r-x));
    s2.insert(x);
}
int main()
{
    n=read();m=read();
    s2.insert(inf);s2.insert(-inf);
    for(int i=1;i<=n;i++)
    {
        int x=read();
        l[i]=r[i]=x;
        push(x);
    }
    for(int i=2;i<=n;i++)
        insert(abs(l[i]-l[i-1]));
    int p,x,t;
    for(int i=1;i<=m;i++)
    {
        char s[20];
        scanf("%s",s);
        if(s[0]=='I')
        {
            p=read();x=read();
            if(p!=n)
			{
				t=abs(r[p]-l[p+1]);
				ma[t]--;
				if(!ma[t])
                    s1.erase(t);
			}
            insert(abs(r[p]-x));
            insert(abs(x-l[p+1]));
            r[p]=x;
            push(x);
        }
        else if(s[4]=='S')printf("%d\n",q.top());
        else printf("%d\n",*s1.begin());
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char c[N];
int a[N];
set<int>s[30];
int main()
{
    scanf("%s",c+1);
    int n=strlen(c+1),q;
    for(int i=1;i<=n;i++)
        a[i]=c[i]-'a',s[a[i]].insert(i);
    scanf("%d",&q);
    while(q--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int x;
            char t[2];
            scanf("%d%s",&x,t);
            s[a[x]].erase(x);
            s[a[x]=t[0]-'a'].insert(x);
        }
        else
        {
            int l,r,cnt=0;
            scanf("%d%d",&l,&r);
            for(int i=0;i<=26;i++)
            {
                if(s[i].empty()) continue;
                int x=*s[i].lower_bound(l);
                if(x>=l&&x<=r) cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}
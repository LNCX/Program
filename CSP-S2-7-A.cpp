#include<bits/stdc++.h>
using namespace std;
set<int>s;
map< int,set<int> >ma;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char c[10];
        int x,y;
        scanf("%s%d%d",c,&x,&y);
        if(c[0]=='a')
        {
            ma[x].insert(y);
            if(ma[x].size()==1)
                s.insert(x);
        }
        else if(c[0]=='r')
        {
            ma[x].erase(y);
            if(ma[x].empty())
                ma.erase(x),s.erase(x);
        }
        else
        {
            int p=*s.upper_bound(x),q=*ma[p].upper_bound(y);
            (p<x||q<y)?puts("-1"):printf("%d %d\n",p,q);
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
map<int,int>ma;
vector<int>v[maxn];
int ans1=0x7fffffff,ans2=0x7fffffff;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        v[i].push_back(x);
        ma[x]++;
        if(i>1) ans1=min(abs(v[i][0]-v[i-1][0]),ans1);
    }
    for(auto it=ma.begin();it!=ma.end();it++)
    {
        if(it->second > 1) ans2=0;
        if(it==ma.begin()) continue;
        int x=it->first,y=(--it)->first;
        ans2=min(abs(x-y),ans2);it++;
    }
    while(m--)
    {
        string s;
        cin>>s;
        if(s=="INSERT")
        {
            int p,w;
            scanf("%d%d",&p,&w);
            int pre=v[p].back(),nxt;
            if(!v[p+1].empty()) nxt=v[p+1].front();
            else nxt=0x3f3f3f3f;
            v[p].push_back(w);
            ans1=min(min(abs(w-pre),abs(w-nxt)),ans1);

            for(auto it=ma.begin();it!=ma.end();it++)
            {
                auto i=it;
                if(it->second > 1) ans2=0;
                if(i==ma.begin()||(++i)==ma.end()) continue;
                i=it; ans2=min(it->first-(--i)->first,ans2);
                i=it; ans2=min(it->first-(++i)->first,ans2);
            }
        }
        if(s=="MIN_GAP") cout<<ans1<<endl;
        if(s=="MIN_SORT_GAP") cout<<ans2<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
map<int,int>ma;
deque<int>q;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(!ma[x]) q.push_back(x),ma[x]=1;
        if((int)q.size()>k)
        {
            ma[q.front()]=0;
            q.pop_front();
        }
    }
    printf("%d\n",(int)q.size());
    while(!q.empty())
    {
        printf("%d ",q.back());
        q.pop_back();
    }
    return 0;
}
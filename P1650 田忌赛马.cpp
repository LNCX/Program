#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n,ans;
vector<int>a,b;
deque<int>qa,qb;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        a.push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        b.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(auto i:a) qa.push_back(i);
    for(auto i:b) qb.push_back(i);
    while(!qa.empty())
    {
        if(qa.back()==qb.back())
        {
            if(qa.front()>qb.front())
            {
                ans++;
                qb.pop_front();
            }
            else
            {
                if(qb.back()>qa.front()) ans--;
                qb.pop_back();
            }
            qa.pop_front();
        }
        else 
        {
            if(qa.back()>qb.back())
            {
                ans++;
                qa.pop_back();
            }
            else
            {
                ans--;
                qa.pop_front();
            }
            qb.pop_back();
        }
    }    
    cout<<ans*200<<endl;
    return 0;
}
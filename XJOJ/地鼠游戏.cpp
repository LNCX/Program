#include<bits/stdc++.h>
using namespace std;
struct node
{
    int t,v;
    friend bool operator<(node x,node y)
    {
        return x.t<y.t;
    }
}a[1000005];
priority_queue<int,vector<int>, greater<int> >q;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].t);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].v);
    sort(a+1,a+1+n);
    int cnt=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt<a[i].t)
        {
            sum+=a[i].v;
            q.push(a[i].v);
            cnt++;
        }
        else
        {
            int x=q.top();
            if(a[i].v>x)
            {
                sum+=a[i].v-x;
                q.pop();
                q.push(a[i].v);
            }
        }
 
    }
    cout<<sum<<endl;
}
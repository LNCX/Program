#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
vector<int>pos[15];
int main()
{
    int n;
    cin>>n;
    a[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pos[a[i]].push_back(i);
    }
    if(n==1) return puts("1"),0;
    for(int i=n;i>=1;i--)
    {
        pos[a[i+1]].pop_back();
        for(int k=1;k<=10;k++)
        {
            if(pos[k].size()==0) continue;
            int x=pos[k].back();
            pos[k].pop_back();
            int ans=0;
            bool flag=true;
            for(int j=1;j<=10;j++)
            {
                if(pos[j].size()!=0&&ans==0) ans=pos[j].size();
                if(pos[j].size()!=0&&ans!=pos[j].size())
                {
                    flag=false;
                    break;
                } 
            }
            if(flag)
            {
                printf("%d\n",i);
                return 0;
            }
            pos[k].push_back(x);
        }
    }
    return 0;
}
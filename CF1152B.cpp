#include<bits/stdc++.h>
using namespace std;
vector<int>a,ans;
int op;
bool check()
{
    for(int i=0;i<(int)a.size();i++)
        if(!a[i]) return false;
    return true;
}
int main()
{
    int x;
    cin>>x;
    while(x)
    {
        a.push_back(x%2);
        x>>=1;
    }
    for(int i=a.size()-1;i>=0;i--)
    {
        if(!a[i])
        {
            ans.push_back(i+1);
            for(int j=i;j>=0;j--)
                a[j]^=1;
            op++;
            if(check()) break;
            a[0]+=1;
            for(int j=0;j<=i;j++)
            {
                if(a[j]!=2) break;
                a[j]=0,a[j+1]+=1;
            }
            op++;
            if(check()) break;
        }
    }
    printf("%d\n",op);
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    puts("");
    return 0;
}
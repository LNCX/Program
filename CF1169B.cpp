#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int a[maxn][2];
vector<int>b;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
            scanf("%d %d",&a[i][0],&a[i][1]);
    for(int k=0;k<2;k++)
    {
        b.clear();
        int x=a[1][k];
        for(int i=1;i<=m;i++)
            if(a[i][0]!=x&&a[i][1]!=x)
                b.push_back(i);
        if(!b.size()) 
        {
            puts("YES");
            return 0;
        }
        for(int j=0;j<2;j++)
        {
            bool flag=true;
            int x=a[b[0]][j];
            for(auto i:b)
            {
                if(a[i][0]!=x&&a[i][1]!=x)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");    
    return 0;
}
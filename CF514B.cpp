#include<bits/stdc++.h>
using namespace std;
set<double>s;
int main()
{
    int n,x,y,flag=0;
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;i++)
    {
        int x1,y1;
        scanf("%d%d",&x1,&y1);
        if(y==y1) flag=1;
        else s.insert((long double)(x-x1)/(y-y1));
    }
    printf("%d\n",s.size()+flag);
}
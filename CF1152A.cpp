#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N];
int one,two,one1,two1;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x%2) one++;
        else two++;
    }
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        if(x%2) one1++;
        else two1++;
    } 
    cout<<min(one,two1)+min(one1,two)<<endl;
    return 0;
}
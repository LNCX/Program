#include<bits/stdc++.h>
using namespace std;
int n;string sx;string xx;
int num=0;string str[1001];int son[1001][1001];int s[1001];int fa[1001];
bool cmp(const int &x,const int &y)
{
    return str[x]<str[y];
}
void pr(int x,int depth)
{
    for(int i=1;i<depth;i++) cout<<"|    ";
    if(depth>0) cout<<"|----";
    cout<<str[x]<<endl;
    for(int i=1;i<=s[x];i++)
    {
        pr(son[x][i],depth+1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>sx;
        int p=0;bool can=0;
        int bef=0;int flag=0;int ll;
        for(int j=0;j<=sx.length();j++)
        {
            if(sx[j]=='/'||j==sx.length())
            {
                xx=sx.substr(p,j-p);can=1;}
            if(can)
            {
                p=j+1;bef=flag;flag=0;
                for(int k=1;k<=num;k++) if(str[k]==xx&&fa[k]==bef) {flag=k;break;}
                if(!flag){flag=++num;str[flag]=xx;if(bef!=0) {ll=++s[bef];son[bef][ll]=flag;fa[flag]=bef;}}can=0;
            }
        }
    }
    for(int i=1;i<=num;i++) sort(son[i]+1,son[i]+s[i]+1,cmp);
    pr(1,0);
    return 0;
}
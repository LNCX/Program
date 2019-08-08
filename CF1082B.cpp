#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
char s[N];
struct node
{
    int l,r;
};
vector<node>a;
int main()
{
    scanf("%d%s",&n,s+1);
    int l=1,r=1,cnt=0;
    int x=0;
    while(l<=n)
    {
        char c='G';
        if(s[l]==c)
        {
            r=l;
            while(r<=n&&s[r]==c)
                r++,cnt++;
            a.push_back((node){l,r-1});
            x=max(r-l,x);
            l=r-1;
        }
        l++;
    }
    if(a.size()>1) 
        x++;
    for(int i=1;i<a.size();i++)
        if(a[i].l==a[i-1].r+2)
            x=max(a[i].r-a[i].l+a[i-1].r-a[i-1].l+3,x);
    cout<<min(cnt,x)<<endl;
    return 0;
}
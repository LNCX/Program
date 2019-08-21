#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
char s[N],t[N];
vector<int>v;
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)
        t[i]='0';
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1') v.push_back(i);
        else if(!v.empty())
        {
            t[v.back()]='1';
            v.pop_back();
        }
    }
    printf("%s\n",t+1);
    return 0;
}
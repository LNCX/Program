#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[N];
int cnt1,cnt0;
int main()
{
    int n;
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='z') cnt0++;
        else if(s[i]=='n') cnt1++;
    }
    while(cnt1--) printf("1 ");
    while(cnt0--) printf("0 ");
    puts("");
    return 0;
}
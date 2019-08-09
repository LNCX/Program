#include<bits/stdc++.h>
using namespace std;
const int N=105;
char s[N];
int n,cnt1,cnt2;
int main()
{
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++)
        s[i]=='1'?cnt1++:cnt2++;
    if(cnt1!=cnt2) printf("%d\n%s\n",1,s+1);
    else
    {
        cout<<2<<endl;
        printf("%c ",s[1]);
        for(int i=2;i<=n;i++)
            printf("%c",s[i]);
        puts("");
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n,a[N],b[N],st[N];
char s[N];
int main()
{
    scanf("%d",&n);
    scanf("%s",s + 1);
    for(int i = 1; i <= n; ++i)
        scanf("%d %d",&a[i],&b[i]),st[i] = s[i] == '1' ? 1 : 0;
    int ans = 0;
    for(int t = 0; t <= 1e5;t++)
    {
        for(int i = 1; i <= n; ++i)
            if(t >= b[i] and (t - b[i]) % a[i] == 0)
                st[i] = !st[i];
        int tot = 0;
        for(int i = 1; i <= n; ++i) tot += st[i];
        if(ans < tot) ans = tot;
    }
    printf("%d\n",ans);
    return 0;
}
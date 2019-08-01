#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N];
int main()
{
    int n, k, lft = 0, t;
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &t);
        if(a[t]) lft--;
        else lft++;
        a[t] ^= 1;
    }
    printf("%d\n", n - lft + (lft + 1) / 2);
    return 0;   
}
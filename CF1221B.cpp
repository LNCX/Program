#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            ((i+j)&1)?putchar('B'):putchar('W');
        puts("");
    }
    return 0;
}
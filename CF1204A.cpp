#include<bits/stdc++.h>
using namespace std;
char a,b[210];
int n,f=1;
int main()
{
    scanf("%c%s",&a,b+1);
    n=strlen(b+1);
    if(n==0) return puts("0");
    for(int i=1;i<=n;i++)
        if(b[i]=='1')
            f=0;
    if(f)n--;
    printf("%d\n",n/2+1);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn],t[maxn];
int main()
{
    scanf("%s",s);
    int tot=-1;
    char lst=0;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]>=lst)
        {
            t[++tot]=s[i];
            lst=s[i];
        }
    }
    while(tot>=0)
        putchar(t[tot--]);
    return 0;
}
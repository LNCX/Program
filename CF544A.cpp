#include<bits/stdc++.h>
using namespace std;
const int N=105;
char s[N];
int n,a[N],used[N],len,cnt,tot;
int main()
{
    cin>>n>>s;
    len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(!used[s[i]-'0'])
        {
            a[i]=1;tot++;
            used[s[i]-'0']=1;
        }
    }
    if(tot<n)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    for(int i=0;i<len;i++)
    {
        cnt++;
        if(a[i])
        {
            if(cnt==n)
            {
                for(int j=i;j<len;j++)
                    printf("%c",s[j]);
                return 0;
            }
            int j;
            printf("%c",s[i]);
            for(j=i+1;a[j]!=1;j++)
                printf("%c",s[j]);
            printf(" ");
            i=j-1;
        }
    }
}
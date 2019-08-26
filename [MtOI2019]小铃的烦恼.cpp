#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
char s[N];
int tax[30],n;
double a[N]={0,0.5},b[N]={0,0.5},f[N],ans;
map<int,int>ma;
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)
        tax[s[i]-'A']++;
    for(int i=2;i<n;i++)
    {
        a[i]=1/(2-a[i-1]);
        b[i]=((n-1.0)/(n-i)+b[i-1])/(2.0-a[i-1]);
    }
    for(int i=n-1;i>=1;i--) 
        f[i]=a[i]*f[i+1]+b[i];
    for(int i=0;i<26;i++) 
        ans+=f[tax[i]];
    printf("%.1lf\n",ans);
    return 0;
}
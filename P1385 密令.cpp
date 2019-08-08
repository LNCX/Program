#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
char s[105];
long long f[110][5000];
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=26;i++) f[1][i]=1; 
    for(int i=2;i<=100;i++)
    {
        f[i][0]=1;
        for(int j=1;j<=2700;j++)
            for(int k=1;k<=26;k++) 
                if (j-k>=1) f[i][j]=(f[i][j]%mod+f[i-1][j-k]%mod)%mod;
    }
    while (t--)
    {
        scanf("%s",s);
        int n=strlen(s),m=0;
        for(int i=0;i<n;i++)
            m+=s[i]-'a'+1;
        cout<<f[n][m]%mod-1<<endl;
    }
    return 0;
}
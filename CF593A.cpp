#include<bits/stdc++.h>
using namespace std;
const int N=105;
int ans;
char s[N][1005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int l='a';l<='z';l++)
        for(int r=l;r<='z';r++)
        {
            int sum=0,cnt=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=strlen(s[i]+1);j++)
                    if(s[i][j]==l||s[i][j]==r)
                        cnt++;
                    else
                    {
                        cnt=0;
                        break;                       
                    }
                sum+=cnt;cnt=0; 
            }
            ans=max(sum,ans);
        }
    cout<<ans<<endl;
    return 0;
}
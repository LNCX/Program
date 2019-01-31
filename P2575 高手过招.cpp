#include<bits/stdc++.h>
using namespace std;
int a[30],cnt[30];
int main()
{
    int t,n;
	cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            int len;
            memset(cnt,0,sizeof cnt);
            cin>>len;
            for(int i=1;i<=len;++i)
            {
            	scanf("%d",&a[i]);
            	cnt[a[i]]++;
			}
            int sum=0,i=20,fg=0;
            while(cnt[i])i--;
            do
            {
                if(!cnt[i])ans^=(fg?sum:0),fg^=1,sum=0;
                else sum++;
            }while(i--);
            ans^=(fg?sum:0);
        }
        cout<<(ans?"YES":"NO")<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const int inf=0x3f3f3f3f;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char s[N];
		int f[N],len;
		bool used[N][N];
		memset(f,inf,sizeof(f));
		memset(used,false,sizeof(used));
		scanf("%s",s+1);
		len=strlen(s+1);
		for(int i=1;i<=len;i++)
		{
			int l=i,r=i;
			while(1<=l&&r<=len&&s[l]==s[r])
			{
				used[l][r]=true;
				l--;r++;	
			}
			l=i,r=i+1;
			while(1<=l&&r<=len&&s[l]==s[r])
			{
				used[l][r]=true;
				l--;r++;	
			}
		}
		f[0]=0;
		for(int i=1;i<=len;i++)
		{
			for(int j=i-1;j>=0;j--)
				if(used[j+1][i])
					f[i]=min(f[i],f[j]+1);
		}
		printf("%d\n",f[len]);
	}
    return 0;
}

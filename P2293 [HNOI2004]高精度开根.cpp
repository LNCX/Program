#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000000;
struct lint
{
	int len;
	unsigned long long num[15000];
};
lint operator +(lint a,lint b)//找bug时看一下有无memset 
{
	lint ans;ans.len=1;
	memset(ans.num,0,sizeof(ans.num));
	while(ans.len<=a.len||ans.len<=b.len)
	{
		ans.num[ans.len]+=a.num[ans.len]+b.num[ans.len];
		ans.num[ans.len+1]+=ans.num[ans.len]/mod;
		ans.num[ans.len]%=mod;
		ans.len++;
	}
	while(ans.len>1&&ans.num[ans.len]==0) ans.len--;
	return ans;
}
lint operator *(lint a,lint b)
{
	lint ans;ans.len=a.len+b.len;
	memset(ans.num,0,sizeof(ans.num));
	for(int i=1;i<=a.len;i++)
		for(int j=1;j<=b.len;j++)
		{
			ans.num[i+j-1]+=a.num[i]*b.num[j];
			ans.num[i+j]+=ans.num[i+j-1]/mod;
			ans.num[i+j-1]%=mod;
		}
	while(ans.len>1&&ans.num[ans.len]==0) ans.len--;
	return ans;
}
lint operator /(lint ans,int b)
{
	for(int i=ans.len;i>=1;i--)
	{
		ans.num[i-1]+=ans.num[i]%b*mod;
		ans.num[i]/=b;
	}
	while(ans.len>1&&ans.num[ans.len]==0) ans.len--;
	ans.num[0]=0; 
	return ans;
}
bool operator <(lint a,lint b)
{
	if(a.len<b.len) 
		return true;
	if(a.len>b.len) 
		return false;
	for(int i=a.len;i>=1;i--)
	{
		if(a.num[i]<b.num[i]) return true;
		if(a.num[i]>b.num[i]) return false;
	}
	return false;
}
lint times(lint a,int p)
{
	lint ans;
	memset(ans.num,0,sizeof(ans.num));
	ans.num[1]=1,ans.len=1; 
	while(p)
	{
		if(p%2==1)
			ans=ans*a;
		a=a*a;
		p/=2;
	}
	return ans;
}
int m;
lint tar,l,r,mid;
void read()
{
	scanf("%d",&m);
	char s[10005];
	scanf("%s",s);
	int lens=strlen(s);
	for(int i=0;i<lens;i++)
	{
		int x=(lens-i-1)/9+1;
		tar.num[x]*=10;
		tar.num[x]+=s[i]-'0';
	}
	tar.len=lens/9+1;
	while(tar.len>0&&tar.num[tar.len]==0) tar.len--;
}
lint start()
{
	lint ans;
	memset(ans.num,0,sizeof(ans.num));
	int x=(tar.len*9)/m+1;
	if(x==0) x=9;
	ans.len=ceil(x/9.0)+1;
	ans.num[ans.len]=1;
	return ans;
}
int main()
{
	read();
	l.len=1;
	l.num[1]=1;
	if(tar.len==0)
	{
		printf("0\n");
		return 0;
	}
	r=start();
	lint one;
	memset(one.num,0,sizeof(one.num));
	one.num[1]=1,one.len=1;
	do
	{
		mid=(l+r)/2;
		if(tar<times(mid,m)) 
			r=mid;
		else l=mid;
	}while((l+one)<r);
	printf("%lld",l.num[l.len]);
	for(int i=l.len-1;i>=1;i--)
		printf("%09lld",l.num[i]);
	printf("\n");
	return 0;
}

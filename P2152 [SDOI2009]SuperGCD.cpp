#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
const unsigned long long mod=10;
struct lint
{
	int len;
	unsigned long long num[maxn]={0};
};//¸ß¾«¶È 
void get(lint &tar)
{
    char s[10005];
    scanf("%s",s);
    int lens=strlen(s);
    for(int i=0;i<lens;i++)
    {
        int x=(lens-i-1)/1+1;
        tar.num[x]*=1;
        tar.num[x]+=s[i]-'0';
    }
    tar.len=lens/1+1;
    while(tar.len>0&&tar.num[tar.len]==0) tar.len--;
}
lint operator +(lint a,lint b)
{
	lint ans;ans.len=1;
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
lint operator -(lint a,lint b)
{
	lint ans;ans.len=1;
	while(ans.len<=a.len||ans.len<=b.len)
	{
		if(a.num[ans.len]<b.num[ans.len])
		{
			a.num[ans.len+1]-=1;
			a.num[ans.len]+=mod;
		}
		ans.num[ans.len]=a.num[ans.len]-b.num[ans.len];
		ans.len++;
	}
	while(ans.len>1&&ans.num[ans.len]==0) ans.len--;
	return ans;
}
lint operator *(lint a,int b)
{
	lint ans=a;ans.len=1;
	for(int i=1;i<=a.len;i++)
	{
		ans.num[i]*=b;
		ans.num[i+1]=ans.num[i]/mod;
		ans.num[i]%=mod;
		ans.len++;
	}
	ans.len++; 
	while(ans.len>1&&ans.num[ans.len]==0) ans.len--;
	return ans;
}
lint operator /(lint a,int b)
{
	lint ans=a;
	for(int i=ans.len;i>=1;i--)
    {
        ans.num[i-1]+=ans.num[i]%b*mod;
        ans.num[i]/=b;
    }
    while(ans.len>1&&ans.num[ans.len]==0) ans.len--;
    ans.num[0]=0; 
    return ans;
}
bool operator ==(lint a,lint b)
{
	if(a.len!=b.len) return false;
    for(int i=a.len;i>=1;i--)
        if(a.num[i]!=b.num[i]) return false;
    return true;
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
lint gcd(lint a,lint b)
{
	lint ans;
	ans.num[1]=1,ans.len=1;
	while(!(a==b))
	{
		if(a.num[1]%2==0&&b.num[1]%2==0) 
		{
			lint ans=gcd(a/2,b/2)*2;
			return ans;
		}
		if(a.num[1]%2==0&&b.num[1]%2==1) 
			return gcd(a/2,b);
		if(a.num[1]%2==1&&b.num[1]%2==0) 
			return gcd(a,b/2);
		if(a.num[1]%2==1&&b.num[1]%2==1)
		{
			if(a<b) swap(a,b);
			return gcd(a-b,b);
		}
	}
	return ans;
	
	if(a==b) return a;
	if(a.num[1]%2==0&&b.num[1]%2==0) 
	{
		lint ans=gcd(a/2,b/2)*2;
		return ans;
	}
	if(a.num[1]%2==0&&b.num[1]%2==1) 
		return gcd(a/2,b);
	if(a.num[1]%2==1&&b.num[1]%2==0) 
		return gcd(a,b/2);
	if(a.num[1]%2==1&&b.num[1]%2==1)
	{
		if(a<b) swap(a,b);
		return gcd(a-b,b);
	}
}
int main()
{
	lint a,b,ans;
	get(a),get(b);
	ans=gcd(a,b);
	printf("%lld",ans.num[ans.len--]);
	for(int i=ans.len;i>=1;i--)
		printf("%017lld",ans.num[i]);
	return 0;
}

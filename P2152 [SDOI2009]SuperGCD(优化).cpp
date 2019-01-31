#include<bits/stdc++.h>
using namespace std;
const int maxn=600;
const unsigned long long mod=1e18;
struct lint
{
	int len;
	unsigned long long num[maxn]={0};
};//高精度 
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
bool operator <=(lint a,lint b)
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
    return true;
} 
lint operator %(lint a,lint b)
{
	while(b<=a) 
		a=a-b;
	return a;
}
void get(lint &tar)
{
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
void print(lint c)
{
	 printf("%lld",c.num[c.len]);
    for(int i=c.len-1;i>=1;i--)
        printf("%018lld",c.num[i]);
    printf("\n");
}
lint a,b,c;
int main()
{
	get(a),get(b);
	while(b.len!=1||b.num[1]!=0)//欧几里得比更相减损快 
	{
		c=a%b;
		a=b;
		b=c;
	}
	print(a); 
	return 0;
}

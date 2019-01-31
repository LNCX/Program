#include<bits/stdc++.h>
using namespace std;
struct lint 
{
	int num[10005]={0};
	int len=0;
};
void get(lint &x)
{
	char s[10005];
	scanf("%s",s);
	x.len=strlen(s);
	for(int i=0;i<x.len;i++)
		x.num[x.len-i]=s[i]-'0';
}
void change(lint &m,lint b,int pos)
{
	for(int i=b.len,j=pos ; i>=1 ; i--,j--)
		m.num[j]=b.num[i];
	m.len=pos;
}
lint operator -(lint a,lint b)
{
	lint c; 
	while(c.len<=a.len||c.len<=b.len)
	{
		if(a.num[c.len]<b.num[c.len])
		{
			a.num[c.len+1]-=1;
			a.num[c.len]+=10;
		}
		c.num[c.len]=a.num[c.len]-b.num[c.len];
		c.len++;
	}
	while(c.num[c.len]==0&&c.len>1) c.len--;
	return c;
}
int cmp(lint a,lint b)
{
	if(a.len<b.len) return 1;
	if(a.len>b.len) return -1;
	for(int i=a.len;i>=1;i--)
	{
		if(a.num[i]<b.num[i]) return 1;
		if(a.num[i]>b.num[i]) return -1;
	}
	return 0;
}
void print(lint x)
{
	while(x.num[x.len]==0&&x.len>1) x.len--;
	for(int i=x.len;i>0;i--)
		printf("%d",x.num[i]);
	printf("\n");
}
int main()
{
	lint a,b,c;
	get(a),get(b);
	c.len=a.len-b.len+1;
	for(int i=a.len;i>0;i--)
	{
		if(cmp(a,b)==1) break;
		lint m;
		change(m,b,i);
		while(cmp(m,a)!=-1)
		{
			a=a-m;
			c.num[i-b.len+1]++;				
		}
	}
	print(c),print(a);
	return 0;
}

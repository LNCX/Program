#include<iostream>
#include<cstring>
#define max 10005
using namespace std;
int a[max],b[max],c[max];
int lena,lenb,lenc=1,x;
char s1[max],s2[max],s3[max];
int change(int m,int n)
{
	int flag=0,count=0;
	if(lena<lenb) flag=1;
	else if(lena>lenb) return 0;
	else
	{
		for(int i=0;i<lena;i++)
		{
			if(s1[i]>s2[i]){flag=0;break;}
			else if(s1[i]<s2[i]) break;
		}
	}
	if(flag)
	{
		int t=lena;lena=lenb;lenb=t;
		strcpy(s3,s1);strcpy(s1,s2);strcpy(s2,s3);
		cout<<"-";
	}
}
int main()
{
	cin>>s1>>s2;
	lena=strlen(s1),lenb=strlen(s2);
	change(lena,lenb);
	for(int i=0;i<lena;i++) a[lena-i]=s1[i]-'0';
	for(int i=0;i<lenb;i++) b[lenb-i]=s2[i]-'0';
	while(lenc<=lena||lenc<=lenb)
	{
		if(a[lenc]<b[lenc])
		{
			a[lenc+1]-=1;
			a[lenc]+=10;
		}
		c[lenc]=a[lenc]-b[lenc];
		lenc++;
	}
	while(c[lenc]==0) lenc--;
	for(int i=lenc;i>0;i--) cout<<c[i];	
}

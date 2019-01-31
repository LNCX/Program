#include<iostream>
#include<cstring>
#define max 10005
using namespace std;
int a[max],b[max],c[max];
int lena,lenb,lenc=1,x;
char s1[max],s2[max];
int main()
{
	cin>>s1>>s2;
	lena=strlen(s1),lenb=strlen(s2);
	for(int i=0;i<lena;i++) a[lena-i]=s1[i]-'0';
	for(int i=0;i<lenb;i++) b[lenb-i]=s2[i]-'0';
	while(lenc<=lena||lenc<=lenb)
	{
		c[lenc]=a[lenc]+b[lenc]+x;
		x=c[lenc]/10;
		c[lenc]%=10;
		lenc++;
	}
	c[lenc]=x;
	if(c[lenc]==0) lenc--;
	for(int i=lenc;i>0;i--) cout<<c[i];
}

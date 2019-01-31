#include<iostream>
#include<cstring>
#define max 1005
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a[max]={0},b[max]={0},c[max]={0};
		int lena,lenb,lenc=1,x=0;
		char s1[max],s2[max];
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
		cout<<endl;
	}
}

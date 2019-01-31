#include<cstring>
#include<iostream>
int a[4000002]={0,1},s[4000002]={0};
int main()
{
	int i,n,lena=1,j,lens=1,k,l=1,v=1;
	scanf("%d",&n);
	for(k=1;k<=n;k++)
	{
		for(j=1;j<=lena;j++) a[j]*=l;
		for(j=1;j<=lena;j++)	
		if(a[j]>=10)
		{
			a[j+1]+=a[j]/10;
			a[j]%=10;
			v++;
		}	
		lena++;
		while(a[lena]>=10)
		{
			a[lena+1]=a[lena]/10;
			a[lena]%=10;
			lena++;
			v++;
		}
		l++;
		lens=lens>lena?lens:lena;
		for(i=1;i<=lens;i++)
		s[i]+=a[i];
		if(s[i]>=10)
		{
			if(i==lens)
				lens++;
			s[i]%=10;
			s[i+1]++;
		}
		lena=v;
	}
	for(i=lens;i>=1;i--)
	{
		if(s[i]==0&&lens>1)
			lens--;
		else
			break;
	}
	for(i=lens;i>=1;i--)printf("%d",s[i]);
}

#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,lena,ans=1,count=1;
char a[105],b[105];
void deal()
{
	for(int i=0;i<strlen(b);i++) a[i]=b[i];
	lena=strlen(b);
	ans=count;
	return;
}
int main()
{
	cin>>n>>a;
	lena=strlen(a);
	for(int i=2;i<=n;i++)
	{
		count++;
		scanf("%s",&b);
		if(lena<strlen(b))
			deal();
		else if(lena==strlen(b))
			for(int i=0;i<lena;i++)
				if(a[i]<b[i]) deal();
	}
	cout<<ans<<endl<<a<<endl;
	return 0;
}


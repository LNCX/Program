#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char a[2000];
		scanf("%s",&a);
		if((a[strlen(a)-1])%2==1) printf("odd\n");
		else printf("even\n");
	}
    return 0;
}


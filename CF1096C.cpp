#include<bits/stdc++.h>
using namespace std;
int a[360];
int main() 
{
	for(int i=3;i<=360;i++)
        for(int j=1;j<i-1;j++)
        {
            if((180*j)%i!=0) continue;
            if(!a[180*j/i]) a[180*j/i]=i;
        }
	int t;
	cin>>t;
	while(t--)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",a[x]);
	}
	return 0;
} 
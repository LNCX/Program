#include<cstdio>
#include<iostream>
#define M 1000000
using namespace std;
long double a[M+1];
int main()
{
    int n,k;
	scanf("%d%d",&n,&k);
	int m=M/k;
	for(int j=0;j<n;j++)
    {
        int x1;
		scanf("%d",&x1);
		long double s=0;
		for(int i=0;i<k;i++)
        {
            int x2;
			scanf("%d",&x2);
			long double r=(long double)(x2-x1)/m;
			for(int t=0;t<=m;t++)
            {
				long double delta=(long double)x1+r*t;
				if(a[i*m+t]<delta)
                {
					s+=delta-a[i*m+t];
					a[i*m+t]=delta;
				}
			}
			x1=x2;
		}
        cout<<s/m<<endl;
	}
	return 0;
}
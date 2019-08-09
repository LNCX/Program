#include<bits/stdc++.h>
#define N 200001
using namespace std;
int a[N] , f[N] , v[N];
int main()
{
    int n,p,t,x=N;
    cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        v[i]=1,t=i,p=a[i];
        while(f[p]!=i)
        {    
            if(f[p]!=0&&f[p]<i) break;        
            v[p]=v[t]+1,f[t]=i;
            t=p,p=a[t];
        }
        if(f[p]==i&&x>v[t]+1-v[p]) 
			x=v[t]+1-v[p];
    }
    printf("%d\n",x);
}

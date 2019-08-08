#include<bits/stdc++.h>
using namespace std;
const int N=505;
int a[N],sum,num,k=1,n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        sum+=a[i],num+=(a[i]==1);
    }
	if(sum<2*n-2) return puts("NO"),0;
	printf("YES %d\n%d\n",min(n-1,n-num+1),n-1);
    int r=0;
    for(int l=1;l<=n;l++) if(a[l]>1)
    {
        if(r) printf("%d %d\n",l,r);
        else a[l]++;
        r=l;
    }
    for(int l=1;l<=n;l++) if(a[l]==1)
    {
		if(r)
        {
            printf("%d %d\n",l,r);
            r=0;continue;
        }
        while(a[k]<=2) 
            k++;
		printf("%d %d\n",l,k);
        a[k]--;
	}
    return  0;
}
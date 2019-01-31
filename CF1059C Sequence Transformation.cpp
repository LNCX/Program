#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t=1;
    scanf("%d",&n);
    while(n>3)
    {
        for(int i=1;i<= ((n+1)>>1);i++) 
			printf("%d ",t);
        n>>=1;
		t<<=1;
    }
    if(n==3)  printf("%d %d %d\n",t,t,t*3);
    else if(n==2) printf("%d %d\n",t,t*2);
    else printf("%d\n",t);
    return 0; 
}

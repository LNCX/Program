#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int b,w,p=2,t=1,y=2;
		cin>>b>>w;
		int i=min(b,w),j=max(b,w);
		if(j>3*i+1) {puts("NO");continue;}
        puts("YES");
		if(b<w) y++;
		while(i>0) printf("%d %d\n",p,y),p+=2,i--;
		while(j>0 && t<p) printf("%d %d\n",t,y),t+=2,j--;t=2;
		while(j>0 && t<p-1) printf("%d %d\n",t,y-1),t+=2,j--;t=2;
		while(j>0) printf("%d %d\n",t,y+1),t+=2,j--;
	}
}
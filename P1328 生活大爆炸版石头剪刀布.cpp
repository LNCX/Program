#include<bits/stdc++.h>
using namespace std;
int s[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int main()
{
	int n,na,nb;
	int a[205],b[205];
	int sa=0,sb=0;
	cin>>n>>na>>nb;
	for(int i=0;i<na;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<nb;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		int x=a[(i-1)%na],y=b[(i-1)%nb];
		if(s[x][y]) sa++;
		else if(s[y][x]) sb++;
	}
	printf("%d %d",sa,sb);
}


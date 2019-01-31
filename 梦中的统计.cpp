#include<cstdio>
int a[10]={0},m,n;
void deal(int x)
{
	while(x)
	{
		a[x%10]++;
		x/=10;
	}
	return;
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=m;i<=n;i++) deal(i);
    for(int i=0;i<10;i++) printf("%d ",a[i]);
    printf("\n");
}


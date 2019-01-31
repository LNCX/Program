#include<bits/stdc++.h>
using namespace std;
int a[505],n;
int f1[505],f2[505];
//f1[i]表示前i个数字分成任意多个递增数且最后的数最小时，最后数是num(f1[i],i),
//f1[i]=max(j),num(f1[j-1],j-1)<num(j,i) 
bool cmp(int l1,int r1,int l2,int r2)
{
	while(a[l1]==0) l1++;
	while(a[l2]==0) l2++;
	if(r1-l1>r2-l2) return false;
	if(r1-l1<r2-l2) return true;
	for(int i=l1,j=l2;i<=r1;i++,j++)
	{
		if(a[i]>a[j]) return false;
		if(a[i]<a[j]) return true;
	}
	return false;
}
int main()
{
	char s[505];
	scanf("%s",s+1);
	n=strlen(s)-1;
	for(int i=1;i<=n;i++)
		a[i]=s[i]-'0';
	for(int i=1;i<=n;i++)
		f1[i]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(cmp(f1[j-1],j-1,j,i))
				f1[i]=max(f1[i],j);
	f2[f1[n]]=n;
	int cnt=0;
    for(int i=f1[n]-1;i&&!a[i];i--) f2[i]=n,cnt++;
    for(int i=f1[n]-1-cnt;i>=1;i--)
	{
        f2[i]=i;
        for(int j=f1[n]-1;j>=i;j--)
		{
            if(cmp(i,j,j+1,f2[j+1])==0)
                f2[i]=max(f2[i],j);
        }
    }
    bool flag=1;
    for(int i=1;i<=n;i=f2[i]+1)
    {
    	if(flag) flag=0;
    	else printf(",");
    	for(int j=i;j<=f2[i];j++)
    		printf("%d",a[j]);
	}
}

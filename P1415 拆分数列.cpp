#include<bits/stdc++.h>
using namespace std;
int a[505],n,cnt,f1[505],f2[505];
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
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		a[i]=s[i]-'0';
	for(int i=1;i<=n;i++) f1[i]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(cmp(f1[j-1],j-1,j,i))
				f1[i]=max(f1[i],j);
	f2[f1[n]]=n;
    for(int i=f1[n]-1;i&&!a[i];i--) f2[i]=n,cnt++;
    for(int i=f1[n]-1-cnt;i>=1;i--)
	{
        f2[i]=i;
        for(int j=i;j<=f1[n]-1;j++)
            if(cmp(i,j,j+1,f2[j+1]))
                f2[i]=max(f2[i],j);
    }
    for(int i=1;i<=n;i=f2[i]+1)
    {
    	if(i!=1) printf(",");
    	for(int j=i;j<=f2[i];j++)
    		printf("%d",a[j]);
	}
}

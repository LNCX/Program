#include<queue>
#include<cstdio>
using namespace std;
const int maxn=2e5+7;
int id[maxn],l[maxn],r[maxn],ans[maxn];
priority_queue<int> q;
int main()
{
    int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;l[i]=i-1,r[i]=i+1,i++)
	{
        int x;
		scanf("%d",&x);
		q.push(x);
		id[x]=i;
	}
	l[0]=r[0]=0;
	l[n+1]=r[n+1]=n+1;
	int p=1;
	while(!q.empty())
	{
		while(!q.empty()&&ans[id[q.top()]]) q.pop();
		if(q.empty()) break;
		int pos=id[q.top()]; q.pop();
		ans[pos]=p;
		int pl=pos,pr=pos;
		for(int i=0;i<k;i++)
		{   
			pl=l[pl];
			pr=r[pr];
			ans[pl]=ans[pr]=p;
		}
		l[r[pr]]=l[pl];
		r[l[pl]]=r[pr];
        p==1?p=2:p=1;
	}
	for(int i=1;i<=n;i++) 
        printf("%d",ans[i]);
    puts("");
	return 0;
}
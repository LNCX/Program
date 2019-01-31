#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[200001];
    priority_queue<int> A;
    priority_queue<int,vector<int>,greater<int> > B;
    int n,m,r=1,q;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
	{
        scanf("%d",&q);
        for(int j=r;j<=q;j++)
		{
            A.push(a[j]);
            if(A.size()==i) 
				B.push(A.top()),A.pop(); 
        }
        r=q+1;
        printf("%d\n",B.top()); 
        A.push(B.top()),B.pop(); 
    }
    return 0;
}


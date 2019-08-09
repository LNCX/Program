#include<bits/stdc++.h>
#define N 10005
using namespace std;
int n,m;
double l, w;
struct Node
{
    double left;
    double right;
    friend bool operator < (const Node&a,const Node&b)
	{
        return a.left < b.left;
    }
}arr[N]; 
int main()
{
    double p,r;
    while(scanf("%d%lf%lf",&n,&l,&w)!=EOF)
	{
        m=0;
        for(int i=0; i<n; ++i)
		{
            scanf("%lf%lf",&p,&r);
            if(w/2>=r) 
                continue;
            double t=sqrt(r*r-w*w/4.0); 
            arr[m].left=p-t;
            arr[m].right=p+t;
            ++m;
        }
        sort(arr,arr+m);
        int cnt=0;
        double left=0, right=0;
        bool flag=false;
        if(arr[0].left <= 0 )
		{
            int i=0;
            while(i < m)
			{
                int j=i;
                while(j<m && left>=arr[j].left)
				{
                    if(arr[j].right > right)
                        right=arr[j].right;
                    ++j;
                }
                if(j==i) break;
                ++cnt;
                left=right;
                i=j;
                if(left>=l)
				{
                    flag=true;
                    break;
                }
            }
        }
        if(flag) printf("%d\n", cnt);
        else printf("-1\n");
    }
    return 0;
} 
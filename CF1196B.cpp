#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        vector<int>ans;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        { 
            scanf("%d",&a[i]);
            a[i]%=2;
        }   
        int sum=0;  
        for(int i=1;i<=n;i++)
        {   
            if(ans.size()==k-1)
            {
                for(i;i<=n;i++)
                    sum+=a[i];
                if(sum%2==1)
                    ans.push_back(n);
                break;
            }
            sum+=a[i];
            if(sum%2==1)
            {
                ans.push_back(i);
                sum=0;
            }
        }
        if(ans.size()!=k) puts("NO");
        else
        {
            puts("YES");
            for(auto i:ans)
                printf("%d ",i);
            puts("");
        }
        
    }
    return 0;
}
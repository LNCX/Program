#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int op,x;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&x);
            q.push(-x);
        }
        else if(op==2)
            printf("%d\n",-q.top());
        else 
            q.pop();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int num,tim,pri;
}data;
bool operator <(node x,node y)
{
    if(x.pri!=y.pri)
        return x.pri<y.pri;
    return x.num>=y.num;
}
priority_queue<node> q;
int a,b,c,d,t;
int main()
{
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)
    {
        while(!q.empty())
        {
            data=q.top();
            q.pop();
            if(t+data.tim<=b)
            {
                t+=data.tim;
                printf("%d %d\n",data.num,t);
            }
            else
            {
                data.tim-=(b-t);
                q.push(data);
                break;
            }
        }
        data.num=a;
        data.tim=c;
        data.pri=d;
        q.push(data);
        t=b;
    }
    while(!q.empty())
    {
        data=q.top();
        q.pop();
        t+=data.tim; 
        printf("%d %d\n",data.num,t);
    }
    return 0;
}

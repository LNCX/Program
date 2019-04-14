#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
inline int read()
{
    int x=0;
    bool f=true;
    char c=getchar();
    while(!isdigit(c)){if(c=='-') f=false;c=getchar();}
    while(isdigit(c)){x=(x*10)+c-'0';c=getchar();}
    return f?x:-x;
}
int n,rt;
void insert(int x,int k)
{

}
void del(int x,int k)
{

}
int pre(int x,int k)
{

}
int back(int x,int k)
{
    
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        int op=read(),x=read();
        switch(op)
        {
            case 1:insert(x,rt);break;
            case 2:del(x,rt);break;
            case 3:printf("%d\n",rnk(x,rt));break;
            case 4:printf("%d\n",num(x,rt));break;
            case 5:ans=0;pre(x,rt);printf("%d\n",tr[ans].v);break;
            case 6:ans=0;back(x,rt);printf("%d\n",tr[ans].v);break;
        }
    }
    return 0;
}
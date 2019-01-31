#include<bits/stdc++.h>
using namespace std;
struct node 
{
    int l,r,v,size,rnd,w;
}tr[100005];
int n,size,root,ans;
void update(int k){tr[k].size=tr[tr[k].l].size+tr[tr[k].r].size+tr[k].w;}
void rturn(int &k)
{
    int t=tr[k].l;tr[k].l=tr[t].r;tr[t].r=k;
    tr[t].size=tr[k].size;update(k);k=t;
}
void lturn(int &k)
{
    int t=tr[k].r;tr[k].r=tr[t].l;tr[t].l=k;
    tr[t].size=tr[k].size;update(k);k=t;
}
void insert(int &k,int x)
{
    if(k==0)
    {
        size++;k=size;
        tr[k].size=tr[k].w=1;tr[k].v=x;tr[k].rnd=rand();
        return;
    }
    tr[k].size++;
    if(tr[k].v==x)tr[k].w++;
    else if(x>tr[k].v)
    {
        insert(tr[k].r,x);
        if(tr[tr[k].r].rnd<tr[k].rnd)lturn(k);
    }
    else
    {
        insert(tr[k].l,x);
        if(tr[tr[k].l].rnd<tr[k].rnd)rturn(k);
    } 
}
void del(int &k,int x)
{
    if(k==0)return; 
    if(tr[k].v==x)
    {
        if(tr[k].w>1)
        {
            tr[k].w--;tr[k].size--;return;
        }
        if(tr[k].l*tr[k].r==0)k=tr[k].l+tr[k].r;
        else if(tr[tr[k].l].rnd<tr[tr[k].r].rnd)
            rturn(k),del(k,x);
        else lturn(k),del(k,x);
    }
    else if(x>tr[k].v)
        tr[k].size--,del(tr[k].r,x);
    else tr[k].size--,del(tr[k].l,x);
}
int rank(int k,int x)
{
    if(k==0)return 0;
    if(tr[k].v==x)return tr[tr[k].l].size+1;
    else if(x>tr[k].v)
        return tr[tr[k].l].size+tr[k].w+rank(tr[k].r,x);
    else return rank(tr[k].l,x);
}
int num(int k,int x)
{
    if(k==0)return 0;
    if(x<=tr[tr[k].l].size)
        return num(tr[k].l,x);
    else if(x>tr[tr[k].l].size+tr[k].w)
        return num(tr[k].r,x-tr[tr[k].l].size-tr[k].w);
    else return tr[k].v;
}
void pre(int k,int x)
{
    if(k==0)return;
    if(tr[k].v<x)
    {
        ans=k;pre(tr[k].r,x);
    }
    else pre(tr[k].l,x);
}
void back(int k,int x)
{
    if(k==0)return;
    if(tr[k].v>x)
        ans=k,back(tr[k].l,x);
    else back(tr[k].r,x);
}
int main()
{
    scanf("%d",&n);
    int opt,x;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&opt,&x);
        switch(opt)
        {
        case 1:insert(root,x);break;
        case 2:del(root,x);break;
        case 3:printf("%d\n",rank(root,x));break;
        case 4:printf("%d\n",num(root,x));break;
        case 5:ans=0;pre(root,x);printf("%d\n",tr[ans].v);break;
        case 6:ans=0;back(root,x);printf("%d\n",tr[ans].v);break;
        }
    }
    return 0;
}

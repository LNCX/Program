#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int size[N],sum[N],upd[N],rev[N],la[N],ra[N],gss[N];
int val[N],ch[N][2],f[N],ncnt,rt;
queue<int>q;
bool chk(int x){return ch[f[x]][1] == x;}
void recycle(int x)
{
    if(ch[x][0]) recycle(ch[x][0]);
    if(ch[x][1]) recycle(ch[x][1]);
    q.push(x);
}
int newnode(int x)
{
    int cur;
    if(q.empty()) cur=++ncnt;
    else cur=q.front(),q.pop();
    ch[cur][0]=ch[cur][1]=f[cur]=0;
    val[cur]=sum[cur]=gss[cur]=x;
    la[cur]=ra[cur]=max(0,x);
    upd[cur]=rev[cur]=0;
    size[cur]=1;
    return cur;
}
void pushup(int x)
{
    int l=ch[x][0],r=ch[x][1];
    size[x]=size[l]+size[r]+1;
    sum[x]=sum[l]+sum[r]+val[x];
    la[x]=max(la[l],sum[l]+val[x]+la[r]);
    ra[x]=max(ra[r],sum[r]+val[x]+ra[l]);
    gss[x]=max(ra[l]+val[x]+la[r],max(gss[l],gss[r]));
}
void rotate(int x)
{
    int y=f[x],z=f[y],k=chk(x),w=ch[x][k^1];
    ch[y][k]=w; f[w]=y;
    ch[z][chk(y)]=x; f[x]=z;
    ch[x][k^1]=y; f[y]=x;
    pushup(y); pushup(x);
}
void pushdown(int x)
{
    int l=ch[x][0],r=ch[x][1];
    if(upd[x])
    {
        upd[x]=rev[x]=0;
        if(l)
        {
            upd[l]=1;
            val[l]=val[x];
            sum[l]=val[x]*size[l];
            la[l]=ra[l]=max(sum[l],0);
            gss[l]=val[x]<0?val[x]:sum[l];
        }
        if(r)
        {
            upd[r]=1;
            val[r]=val[x];
            sum[r]=val[x]*size[r];
            la[r]=ra[r]=max(sum[r],0);
            gss[r]=val[x]<0?val[x]:sum[r];
        }
    }
    if(rev[x])
    {
        rev[l]^=1;rev[r]^=1;
        rev[x]=0;
        swap(la[l],ra[l]),swap(la[r],ra[r]);
        swap(ch[l][0],ch[l][1]);
        swap(ch[r][0],ch[r][1]);
    }
}
void splay(int x,int k=0)
{
    while(f[x]!=k)
    {
        int y=f[x],z=f[y];
        if(z!=k)
        {
            if(chk(x)==chk(y)) rotate(y);
            else rotate(x);
        }
        rotate(x);
    }
    if(!k) rt=x;
}
int build(int l,int r,int *arr)
{
    if(l>r) return 0;
    int mid=(l+r)>>1,cur=newnode(arr[mid]);
    if(l==r) return cur;
    if((ch[cur][0]=build(l,mid-1,arr))) f[ch[cur][0]]=cur;
    if((ch[cur][1]=build(mid+1,r,arr))) f[ch[cur][1]]=cur;
    pushup(cur);
    return cur;
}
int kth(int k)
{
    int cur=rt;
    while(1)
    {
        pushdown(cur);
        if(ch[cur][0]&&k<=size[ch[cur][0]])
            cur=ch[cur][0];
        else if(k > size[ch[cur][0]]+1)
        {
            k-=size[ch[cur][0]]+1;
            cur=ch[cur][1];
        } 
        else return cur;
    }
}
void insert(int x,int y)
{
    int u=kth(x+1),v=kth(x+2);
    splay(u),splay(v,u);
    ch[v][0]=y; f[y]=v;
    pushup(v),pushup(u); 
}
int qsum(int x,int y)
{
    int u=kth(x),v=kth(x+y+1);
    splay(u),splay(v,u);
    return sum[ch[v][0]];
}
void remove(int x,int y)
{
    int u=kth(x),v=kth(x+y+1);
    splay(u),splay(v,u);
    recycle(ch[v][0]);
    ch[v][0]=0;
    pushup(v),pushup(u);
}
void reverse(int x,int y)
{
    int u=kth(x),v=kth(x+y+1);
    splay(u),splay(v,u);
    int w=ch[v][0];
    if(!upd[w])
    {
        rev[w]^=1;
        swap(ch[w][0],ch[w][1]);
        swap(la[w],ra[w]);
        pushup(v),pushup(u);
    }
}
void update(int x,int y,int z)
{
    int u=kth(x),v=kth(x+y+1);
    splay(u),splay(v,u);
    int w=ch[v][0];
    upd[w]=1,val[w]=z,sum[w]=size[w] * z;
    la[w]=ra[w]=max(0,sum[w]);
    gss[w]=z<0?z:sum[w];
    pushup(v),pushup(u);
}
int n,m,arr[N],c,x,y,z;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n+1;i++)
        scanf("%d",&arr[i]);
    gss[0]=val[0]=0xcfcfcfcf;
    arr[1]=arr[n+=2]=0xcfcfcfcf;
    build(1,n,arr); rt=1;
    while (m--)
    {
        char s[32];
        scanf("%s",s);
        switch((s[2]+s[1])^*s)
        {
            case 'G'^('E'+'T'):
                scanf("%d%d",&x,&y);
                printf("%d\n",qsum(x,y));
                break;
            case 'M'^('A'+'X'):
                printf("%d\n",gss[rt]);
                break;
            case 'R'^('E'+'V'):
                scanf("%d%d",&x,&y);
                reverse(x,y);
                break;
            case 'M'^('A'+'K'):
                scanf("%d%d%d",&x,&y,&z);
                update(x,y,z);
                break;
            case 'D'^('E'+'L'):
                scanf("%d%d",&x,&y);
                remove(x,y);
                break;
            case 'I'^('N'+'S'):
                scanf("%d%d",&x,&y);
                memset(arr,0,sizeof arr);
                for(int i=1;i<=y;i++)
                    scanf("%d",arr+i);
                insert(x,build(1,y,arr));
                break;
        }
    }
}
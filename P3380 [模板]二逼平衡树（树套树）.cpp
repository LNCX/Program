#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5,inf=0x7fffffff;
int a[N],b[N],num,n,m,blg[N],L[N],R[N];
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-') f=false;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c-'0');c=getchar();}
    return f?x:-x;
}
void build()
{
    int t=sqrt(n);
    num=n/t;
    if(n%t) num++;
    for(int i=1;i<=n;i++)
        blg[i]=(i-1)/t+1,b[i]=a[i];
    for(int i=1;i<=num;i++)
        L[i]=(i-1)*t+1,R[i]=i*t;
    R[num]=n;
    for(int i=1;i<=num;i++)
        sort(b+L[i],b+R[i]+1);
}
int search(int l,int r,int k,int type)
{
    int p=0;
    if(!type)
    {
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(b[mid]<k) p=mid,l=mid+1;
            else r=mid-1;
        }   
    }
    else
    {
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(b[mid]>k) p=mid,r=mid-1;
            else l=mid+1;
        }
    }
    return p;
}
int find(int k,int r,int l)
{
    int cnt=1;
    if(blg[l]==blg[r])
    {
        for(int i=l;i<=r;i++)
            if(a[i]<k) cnt++;
        return cnt;
    }
    for(int i=l;i<=R[blg[l]];i++) if(a[i]<k) cnt++;
    for(int i=L[blg[r]];i<=r;i++) if(a[i]<k) cnt++;
    for(int i=blg[l]+1;i<blg[r];i++)
        if(b[L[i]]<k) cnt+=search(L[i],R[i],k,0)-(L[i]-1);
	return cnt;
}
int order(int k,int r,int l)
{
    if(blg[l]==blg[r])
    {
    	vector<int>v;
    	for(int i=l;i<=r;i++)
    		v.push_back(a[i]);
    	sort(v.begin(),v.end());
    	return v[k-1];
	}
    int lk=0,rk=1e8,res;
    while(lk<=rk)
    {
        int mid=(lk+rk)>>1;
        if(find(mid,r,l)<=k) res=mid,lk=mid+1;
        else rk=mid-1;
    }
    return res;
}
void change(int k,int p)
{
    a[p]=k;
    for(int i=L[blg[p]];i<=R[blg[p]];i++)
        b[i]=a[i];
    sort(b+L[blg[p]],b+R[blg[p]]+1);
}
int pre(int k,int r,int l)
{
    #define turn(i,a) (a[i]<k&&a[i]>res)?res=a[i]:res=res
    int res=-inf;
    if(blg[l]==blg[r])
    {
        for(int i=l;i<=r;i++) turn(i,a);
        return res==inf?-res:res;
    }
    for(int i=l;i<=R[blg[l]];i++) turn(i,a);
    for(int i=L[blg[r]];i<=r;i++) turn(i,a);
    for(int i=blg[l]+1;i<blg[r];i++)
        if(b[L[i]]<k) turn(search(L[i],R[i],k,0),b);
    return res;
    #undef turn
}
int suc(int k,int r,int l)
{
    #define turn(i,a) (a[i]>k&&a[i]<res)?res=a[i]:res=res
    int res=inf;
    if(blg[l]==blg[r])
    {
        for(int i=l;i<=r;i++) turn(i,a);
        return res==-inf?-res:res;
    }
    for(int i=l;i<=R[blg[l]];i++) turn(i,a);
    for(int i=L[blg[r]];i<=r;i++) turn(i,a);
    for(int i=blg[l]+1;i<blg[r];i++)
        if(b[R[i]]>k) turn(search(L[i],R[i],k,1),b);
    return res;
    #undef turn
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    build();
    while(m--)
    {
        int op=read();
        if(op==1) printf("%d\n",find(read(),read(),read()));
        if(op==2) printf("%d\n",order(read(),read(),read()));
        if(op==3) change(read(),read());
        if(op==4) printf("%d\n",pre(read(),read(),read()));
        if(op==5) printf("%d\n",suc(read(),read(),read()));
    }
    return 0;
}
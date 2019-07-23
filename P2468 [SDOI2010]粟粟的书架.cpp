#include<stdio.h>
int n,m,q;
namespace solve1
{
    const int N=5e5+5;
    int a[N],t[N],ch[N*15][2],sum[N*15],cnt[N*15],tot;
    int build(int l,int r)
    {
        int rt=++tot,mid=(l+r)>>1;
        if(l==r) return rt;
        ch[rt][0]=build(l,mid);
        ch[rt][1]=build(mid+1,r);
        return rt;
    }
    int update(int pre,int l,int r,int x)
    {
        int rt=++tot,mid=(l+r)>>1;
        ch[rt][0]=ch[pre][0],ch[rt][1]=ch[pre][1];
        cnt[rt]=cnt[pre]+1,sum[rt]=sum[pre]+x;
        if(l==r) return rt;
        if(x<=mid) ch[rt][0]=update(ch[pre][0],l,mid,x);
        else ch[rt][1]=update(ch[pre][1],mid+1,r,x);
        return rt;
    }
    int query(int u,int v,int l,int r,int k)
    {
        int ans=0;
        while(l<r)
        {
            int mid=(l+r)>>1;
            int x=sum[ch[v][1]]-sum[ch[u][1]];
            if(x<k)
            {
                ans+=cnt[ch[v][1]]-cnt[ch[u][1]];
                k-=x,r=mid;
                v=ch[v][0],u=ch[u][0];
            }
            else l=mid+1,v=ch[v][1],u=ch[u][1];
        }
        ans+=(k+l-1)/l;
        return ans;
    }
    int main()
    {
        t[0]=build(1,m);
        for(int i=1;i<=m;i++)
        {
            int x;
            scanf("%d",&x);
            t[i]=update(t[i-1],1,1000,x);
        }        
        while(q--)
        {
            int x1,y1,x2,y2,k;
            scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&k);
            if(sum[t[y2]]-sum[t[y1-1]]<k) puts("Poor QLW");
            else printf("%d\n",query(t[y1-1],t[y2],1,1000,k));
        }
        return 0;
    }
}
namespace solve2
{
    const int N=205,M=1e3+5;
    int a[N][N],cnt[N][N][M],val[N][N][M];
    int calv(int x1,int y1,int x2,int y2,int k){return val[x2][y2][k]-val[x1-1][y2][k]+val[x1-1][y1-1][k]-val[x2][y1-1][k];}
    int caln(int x1,int y1,int x2,int y2,int k){return cnt[x2][y2][k]-cnt[x1-1][y2][k]+cnt[x1-1][y1-1][k]-cnt[x2][y1-1][k];}
    int main()
    {
        int maxn=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]>maxn) maxn=a[i][j];
            }
        for(int k=0;k<=maxn;++k) 
            for(int i=1;i<=n;++i)
                for(int j=1;j<=m;++j)
                {
                    val[i][j][k]=val[i-1][j][k]+val[i][j-1][k]-val[i-1][j-1][k]+(a[i][j]>=k?a[i][j]:0);
                    cnt[i][j][k]=cnt[i-1][j][k]+cnt[i][j-1][k]-cnt[i-1][j-1][k]+(a[i][j]>=k?1:0);
                }
        while(q--)
        {
            int x1,y1,x2,y2,k;
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&k);
            if(calv(x1,y1,x2,y2,0)<k) 
            {
                puts("Poor QLW");
                continue;
            }
            int l=0,r=maxn+1,ans=-1;
            while(l+1<r)
            {
                int mid=(l+r)>>1;
                if(calv(x1,y1,x2,y2,mid)>=k) l=mid,ans=mid;
                else r=mid;
            }
            if(ans==-1) puts("Poor QLW");
            else printf("%d\n",caln(x1,y1,x2,y2,ans)-(calv(x1,y1,x2,y2,ans)-k)/ans);
        }
        return 0;
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    if(n==1) solve1::main();
    else solve2::main();
    return 0;
}
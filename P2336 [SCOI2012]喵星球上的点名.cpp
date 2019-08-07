#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;
using std::sort;
const int MAXN=440000;
const int MAXB=20;
const int MAXS=1E4;
int n, m, l;
int a[MAXN], b[MAXN];
int len[MAXN], fir[MAXN];
int sa[MAXN], rank[MAXN*2], rank1[MAXN];
int count[MAXN], tmp[MAXN], height[MAXN];
int lef[MAXN], righ[MAXN];
int root[MAXN], pre[MAXN], ans[MAXN];
struct Interval
{
    int l, r;
    bool operator < (const Interval& rhs) const
    {
        return r<rhs.r;
    }
} d[MAXN];
struct RMQ
{
    int lg[MAXN], st[MAXN][MAXB];
    void build(int* a)
    {
        for(int i=1, k=0; i<=l; i++) lg[i]=1<<k+1==i?++k:k;
        for(int i=1; i<=l; i++) st[i][0]=a[i];
        for(int j=1; 1<<j<=l; j++)
            for(int i=1; i+(1<<j)-1<=l; i++)
                st[i][j]=min(st[i][j-1], st[i+(1<<j-1)][j-1]);
    }
    int lcp(int l, int r)
    {
        int k=lg[r-l];
        return min(st[l+1][k], st[r-(1<<k)+1][k]);
    }
} st;
struct PersistableSegmentTree
{
    struct Node
    {
        int val, lc, rc;
    } tr[MAXN<<5];
    int cnt;
    void pushup(int x)
    {
        tr[x].val=tr[tr[x].lc].val+tr[tr[x].rc].val;
    }
    void insert(int& x, int y)
    {
        tr[x=++cnt]=tr[y];
    }
    void update(int& x, int y, int l, int r, int p, int k)
    {
        insert(x, y);
        if(l==r) { tr[x].val+=k; return; }
        int mid=l+r>>1;
        if(p<=mid) update(tr[x].lc, tr[y].lc, l, mid, p, k);
        else update(tr[x].rc, tr[y].rc, mid+1, r, p, k);
        pushup(x);
    }
    int query(int x, int l, int r, int ql, int qr)
    {
        if(l>qr||r<ql) return 0;
        if(ql<=l&&r<=qr) return tr[x].val;
        int mid=l+r>>1;
        return query(tr[x].lc, l, mid, ql, qr)
              +query(tr[x].rc, mid+1, r, ql, qr);
    }
} pst;
struct BinaryIndexedTree
{
    #define lb(x) (x&-(x))
    int s[MAXN];
    void add(int x, int k)
    {
        while (x<=l) s[x]+=k, x+=lb(x);
    }
    int sum(int x)
    {
        int res=0;
        while (x>0) res+=s[x], x-=lb(x);
        return res;
    }
    #undef lb
} bit;
int getstr(int id)
{
    static int cnt=0;
    int k; scanf("%d", &k);
    for(int i=1; i<=k; i++)
        scanf("%d", &a[++l]), b[l]=id;
    a[++l]=MAXS+(++cnt);
    return k;
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) getstr(i), getstr(i);
    for(int i=1; i<=m; i++) len[i]=getstr(0), fir[i]=l-len[i];
    memset(count, 0, sizeof count);
    memset(rank, 0, sizeof rank);
    for(int i=1; i<=l; i++) count[a[i]]=1;
    for(int i=1; i<MAXN; i++) count[i]+=count[i-1];
    for(int i=1; i<=l; i++) rank[i]=count[a[i]];
    for(int p=1, k=0; k!=l; p<<=1)
    {
        memset(count, 0, sizeof count);
        for(int i=1; i<=l; i++) count[rank[i+p]]++;
        for(int i=1; i<=l; i++) count[i]+=count[i-1];
        for(int i=l; i>=1; i--) tmp[count[rank[i+p]]--]=i;
        memset(count, 0, sizeof count);
        for(int i=1; i<=l; i++) count[rank[i]]++;
        for(int i=1; i<=l; i++) count[i]+=count[i-1];
        for(int i=l; i>=1; i--) sa[count[rank[tmp[i]]]--]=tmp[i];
        memcpy(rank1, rank, sizeof rank1);
        rank[sa[1]]=k=1;
        for(int i=2; i<=l; i++)
        {
            if(rank1[sa[i]]!=rank1[sa[i-1]]
              ||rank1[sa[i]+p]!=rank1[sa[i-1]+p]) k++;
            rank[sa[i]]=k;
        }
    }
    for(int i=1, k=0; i<=l; i++)
    {
        if(rank[i]==1)
        {
            height[rank[i]]=k=1;
            continue;
        }
        if(--k<0) k=0;
        while (a[i+k]==a[sa[rank[i]-1]+k]) k++;
        height[rank[i]]=k;
    }
    st.build(height);
    for(int i=1; i<=m; i++)
    {
        lef[i]=righ[i]=rank[fir[i]];
        for(int j=MAXB-1; j>=0; j--)
            if(lef[i]-(1<<j)>=1&&st.lcp(lef[i]-(1<<j), rank[fir[i]])>=len[i])
                lef[i]-=1<<j;
        for(int j=MAXB-1; j>=0; j--)
            if(righ[i]+(1<<j)<=l&&st.lcp(rank[fir[i]], righ[i]+(1<<j))>=len[i])
                righ[i]+=1<<j;
        d[i].l=lef[i]; d[i].r=righ[i];
    }
    sort(d+1, d+m+1);
    for(int i=1; i<=m; i++) bit.add(d[i].l, 1);
    memset(pre, 0, sizeof pre);
    for(int i=1, j=1; i<=l; i++)
        if(b[sa[i]]==0) pst.insert(root[i], root[i-1]);
        else
        {
            if(!pre[b[sa[i]]]) pst.update(root[i], root[i-1], 1, l, i, 1);
            else
            {
                int temp;
                pst.update(temp, root[i-1], 1, l, pre[b[sa[i]]], -1);
                pst.update(root[i], temp, 1, l, i, 1);
            }
            while (j<=m&&d[j].r<i) bit.add(d[j++].l, -1);
            ans[b[sa[i]]]+=bit.sum(i)-bit.sum(pre[b[sa[i]]]);
            pre[b[sa[i]]]=i;
        }
    for(int i=1; i<=m; i++)
        printf("%d\n", pst.query(root[righ[i]], 1, l, lef[i], righ[i]));
    for(int i=1; i<=n; i++) printf("%d ", ans[i]); putchar('\n');
    return 0;
}
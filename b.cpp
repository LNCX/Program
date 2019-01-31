#include <cstdio>

#define re register
#define LL long long
#define isnum(x) ('0' <= x && x <= '9')

inline int getint()
{
    int res = 0, neg = 0, ch = getchar();
    while(!(isnum(ch) || ch == '-') && ch != EOF)
        ch = getchar();
    if(ch == '-')
        neg = 1, ch = getchar();
    while(isnum(ch))
        res = (res << 3) + (res << 1) + (ch - '0'), ch = getchar();
    if(neg)
        res = -res;
    return res;
}

int m, n;
LL w[100010];

int first[100010], to[200010], nxt[200010], cnt = 0;

int fa[100010], siz[100010], id[100010], idcnt = 0, ref[100010], Maxson[100010];
int topfa[100010];

struct Sinfo
{
    LL sum;
    LL add;
}S[400010];

inline void addE(int u, int v)
{
    ++cnt;
    to[cnt] = v;
    nxt[cnt] = first[u];
    first[u] = cnt;
}

void dfsA(int u, int FA)
{	
    fa[u] = FA;
    siz[u] = 1;
    
    int Max = 0;
    
    for(re int p = first[u]; p; p = nxt[p])
    {
        int v = to[p];
        if(v == FA)
            continue;
        
        dfsA(v, u);
        
        if(siz[v] > Max)
        {
            Maxson[u] = v;
            Max = siz[v];
        }
        siz[u] += siz[v];
    }
}

void dfsB(int u, int topFA)
{
    ++idcnt;
    id[u] = idcnt;
    ref[idcnt] = u;	
    
    topfa[u] = topFA;

    if(Maxson[u] == 0)
        return;
    
    dfsB(Maxson[u], topFA);
    
    for(re int p = first[u]; p; p = nxt[p])
    {
        int v = to[p];
        
        if(v == fa[u] || v == Maxson[u])
            continue;
        
        dfsB(v, v);
    }
}

void build(int k, int l, int r)
{
    if(l == r)
    {
        S[k].sum = w[ ref[l] ];
        S[k].add = 0;
        return;
    }
    
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build((k << 1) + 1, mid+1, r);
    S[k].sum = S[k << 1].sum + S[(k << 1) + 1].sum;
    S[k].add = 0;
}

void pushdown(int k, int l, int r)
{
    int mid = (l + r) >> 1;
    
    S[k << 1].sum += (S[k].add) * (mid - l + 1);
    S[k << 1].add += S[k].add;
    
    S[(k << 1) + 1].sum += (S[k].add) * (r - mid);
    S[(k << 1) + 1].add += S[k].add;
    
    S[k].add = 0;
}

void modifyA(int k, int l, int r, int x, LL VAL)
{
    if(x < l || r < x)
        return;
    if(l == r)//single
    {
        S[k].sum += VAL;
        return;
    }
    
    pushdown(k, l, r);
    
    int mid = (l + r) >> 1;
    modifyA(k << 1, l, mid, x, VAL);
    modifyA((k << 1) + 1, mid+1, r, x, VAL);
    
    S[k].sum = S[k << 1].sum + S[(k << 1) + 1].sum;
}

void modifyB(int k, int l, int r, int x, int y, LL VAL)
{
    if(y < l || r < x)
        return;
    if(x <= l && r <= y)
    {
        S[k].sum += VAL * (r - l + 1);
        S[k].add += VAL;
        return;
    }
    
    pushdown(k, l, r);
    
    int mid = (l + r) >> 1;
    modifyB(k << 1, l, mid, x, y, VAL);
    modifyB((k << 1) + 1, mid+1, r, x, y, VAL);
    
    S[k].sum = S[k << 1].sum + S[(k << 1) + 1].sum;
}

LL query(int k, int l, int r, int x, int y)
{
    if(y < l || r < x)
        return 0;
    if(x <= l && r <= y)
        return S[k].sum;
    
    pushdown(k, l, r);
    
    int mid = (l + r) >> 1;
    return query(k << 1, l, mid, x, y) + query((k << 1) + 1, mid + 1, r, x, y);
}

LL queryPath(int x)
{
    LL res = 0;
    while(topfa[x] != 1)
    {
        res += query(1, 1, n, id[ topfa[x] ], id[x]);
        x = fa[ topfa[x] ];
    }
    res += query(1, 1, n, 1, id[x]);
    return res;
}

int main()
{
    n = getint(), m = getint();
    for(re int i = 1; i <= n; ++i)
        w[i] = getint();
    for(re int i = 1; i <= n-1; ++i)
    {
        int u = getint(), v = getint();
        addE(u, v);
        addE(v, u);
    }
    
    dfsA(1, 0);
    dfsB(1, 1);
    
    build(1, 1, n);
    
    while(m--)
    {
        int op = getint();
        if(op == 1)
        {
            int x = getint();
            LL VAL = getint();
            modifyA(1, 1, n, id[x], VAL);
        }
        else
        if(op == 2)
        {
            int x = getint();
            LL VAL = getint();
            modifyB(1, 1, n, id[x], id[x] + siz[x] - 1, VAL);
        }
        else
        {
            int x = getint();
            printf("%lld\n", queryPath(x));
        }
    }
    
    return 0;
} 
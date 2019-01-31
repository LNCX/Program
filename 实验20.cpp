#include <bits/stdc++.h>
#define LL long long

using namespace std;

int n, m;
LL p;

int a[100010];

struct Tinfo
{
    LL sum;
    LL mul, add;
}T[400010];

int getint()
{
    int res = 0;
    bool _neg = false;
    char ch = getchar();
    while(!(('0' <= ch && ch <= '9') || ch == '-'))
        ch = getchar();
    if(ch == '-')
    {
        _neg = true;
        ch = getchar();
    }
    while('0' <= ch && ch <= '9')
    {
        res = (res << 3) + (res << 1) + (ch - '0');
        ch = getchar();
    }
    if(_neg)
        res = -res;
    return res;
}

void pushdown(int k, int l, int r)
{
    int mid = (l + r) >> 1;
    
    //to left son
    T[k << 1].sum = (T[k << 1].sum * T[k].mul + T[k].add * (mid - l + 1)) % p;
    T[k << 1].mul = (T[k << 1].mul * T[k].mul) % p;
    T[k << 1].add = (T[k << 1].add * T[k].mul + T[k].add) % p;
    
    //to right son
    T[(k << 1) + 1].sum = (T[(k << 1) + 1].sum * T[k].mul + T[k].add * (r - mid)) % p;
    T[(k << 1) + 1].mul = (T[(k << 1) + 1].mul * T[k].mul) % p;
    T[(k << 1) + 1].add = (T[(k << 1) + 1].add * T[k].mul + T[k].add) % p;
    
    T[k].mul = 1;
    T[k].add = 0;
}

void build(int k, int l, int r)
{
    T[k].add = 0;
    T[k].mul = 1;
    if(l == r)
        T[k].sum = a[l];
    else
    {
        int mid = (l + r) >> 1;
        build(k << 1, l, mid);
        build((k << 1) + 1, mid+1, r);
        T[k].sum = T[k << 1].sum + T[(k << 1) + 1].sum;
    }
}

void modifyMul(int k, int l, int r, int x, int y, LL val)
{
    if(y < l || r < x)
        return;
    //else
    if(x <= l && r <= y)
    {
        T[k].sum = T[k].sum * val % p;
        T[k].mul = T[k].mul * val % p;
        T[k].add = T[k].add * val % p;
        return;
    }
    //else broke it
    pushdown(k, l, r);
    
    int mid = (l + r) >> 1;
    modifyMul(k << 1, l, mid, x, y, val);
    modifyMul((k << 1) + 1, mid+1, r, x, y, val);
    
    T[k].sum = (T[k << 1].sum + T[(k << 1) + 1].sum) % p;
}

void modifyAdd(int k, int l, int r, int x, int y, LL val)
{
    if(y < l || r < x)
        return;
    //else
    if(x <= l && r <= y)
    {
        T[k].sum = (T[k].sum + (r - l + 1) * val) % p;
        T[k].add = (T[k].add + val) % p;
        return;
    }
    //else broke it
    pushdown(k, l, r);
    
    int mid = (l + r) >> 1;
    modifyAdd(k << 1, l, mid, x, y, val);
    modifyAdd((k << 1) + 1, mid+1, r, x, y, val);
    
    T[k].sum = (T[k << 1].sum + T[(k << 1) + 1].sum) % p;
}

LL query(int k, int l, int r, int x, int y)
{
    if(y < l || r < x)
        return 0;
    if(x <= l && r <= y)
        return T[k].sum;
    
    pushdown(k, l, r);
    
    int mid = (l + r) >> 1;
    return (query(k << 1, l, mid, x, y) + query((k << 1) + 1, mid+1, r, x, y)) % p;
}

int main()
{
    n = getint(), p = getint();
    for(int i = 1; i <= n; ++i)
        a[i] = getint();
    build(1, 1, n);
    
    m = getint();
    
    while(m--)
    {
        int op = getint();
        if(op == 1)
        {
            int x = getint(), y = getint();
            LL val = getint();
            modifyMul(1, 1, n, x, y, val);
        }
        else
        if(op == 2)
        {
            int x = getint(), y = getint();
            LL val = getint();
            modifyAdd(1, 1, n, x, y, val);
        }
        else
        {
            int x = getint(), y = getint();
            printf("%lld\n", query(1, 1, n, x, y));
        }
    }
    return 0;
}


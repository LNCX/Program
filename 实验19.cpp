#pragma GCC optimize(2) //O2优化
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define lson rt << 1 //简化书写
#define rson rt << 1 | 1

const int N = 200007; //数据范围有误，100000会RE
typedef long long ll;

int n, q, L, R, op;
ll k, P, a[N];

struct SegmentTree
{
    ll sum[N << 2], mtp[N << 2], inc[N << 2];

    void down(int rt, int l, int r)
    {
        if (mtp[rt] == 1 && inc[rt] == 0) return; //都为初始状态时无需下传
        if (l != r)
            mtp[lson] = mtp[lson] * mtp[rt] % P, //儿子的mtp乘以当前节点mtp
            mtp[rson] = mtp[rson] * mtp[rt] % P, 
            inc[lson] = (inc[lson] * mtp[rt] % P + inc[rt]) % P; //儿子的inc乘以当前节点mtp再加当前节点inc
            inc[rson] = (inc[rson] * mtp[rt] % P + inc[rt]) % P;
        sum[rt] = (sum[rt] * mtp[rt] % P + inc[rt] * (r - l + 1) % P) % P; //更新节点信息
        mtp[rt] = 1, inc[rt] = 0; //清空标记
    }

    void build(int rt, int l, int r) //根据数组构建线段树，当然打insert也是可以的
    {
        mtp[rt] = 1, inc[rt] = 0; //初始化标记
        if (l == r) { sum[rt] = a[l]; return; }
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        sum[rt] = sum[lson] + sum[rson];
    }

    ll qrysum(int rt, int l, int r)
    {
        down(rt, l, r); //先下传标记
        if (L <= l && r <= R) return sum[rt];
        ll ret = 0; int mid = l + r >> 1;
        if (L <= mid) ret = (ret + qrysum(lson, l, mid)) % P;
        if (mid + 1 <= R) ret = (ret + qrysum(rson, mid + 1, r)) % P;
        return ret;
    }

    void rangeplus(int rt, int l, int r)
    {
        down(rt, l, r); //先下传标记
        if (L <= l && r <= R) { inc[rt] = (inc[rt] + k) % P; return; } //区间更新，inc加上k
        int mid = l + r >> 1;
        if (L <= mid) rangeplus(lson, l, mid);
        if (mid + 1 <= R) rangeplus(rson, mid + 1, r);
        down(lson, l, mid), down(rson, mid + 1, r); //下传儿子的标记
        sum[rt] = (sum[lson] + sum[rson]) % P;
    }

    void rangemtp(int rt, int l, int r)
    {
        down(rt, l, r); //先下传标记
        if (L <= l && r <= R) { mtp[rt] = mtp[rt] * k % P, inc[rt] = inc[rt] * k % P; return; } //区间更新，mtp和inc都乘以一个k
        int mid = l + r >> 1;
        if (L <= mid) rangemtp(lson, l, mid);
        if (mid + 1 <= R) rangemtp(rson, mid + 1, r);
        down(lson, l, mid), down(rson, mid + 1, r); //下传儿子的标记
        sum[rt] = (sum[lson] + sum[rson]) % P;
    }
} tree;

inline ll read() //读入加速
{
    ll x = 0, f = 0;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar()) if (c == '-') f = 1;
    for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + c - '0';
    return f ? -x : x;
}

void init()
{
    n = read(), P = read();
    for (int i = 1; i <= n; i++) *(a + i) = read();
    tree.build(1, 1, n);
}

void solve()
{
    q = read();
    while (q!=0)
    {
    	q--;
        op = read();
        if (op == 1)
            L = read(), R = read(), k = read(),
            tree.rangemtp(1, 1, n);
        else if (op == 2)
            L = read(), R = read(), k = read(),
            tree.rangeplus(1, 1, n);
        else
            L = read(), R = read(),
            printf("%lld\n", tree.qrysum(1, 1, n));
    }
}

int main()
{
    init();
    P=1e6;
    solve();
    return 0;
}

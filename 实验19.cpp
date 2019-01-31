#pragma GCC optimize(2) //O2�Ż�
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define lson rt << 1 //����д
#define rson rt << 1 | 1

const int N = 200007; //���ݷ�Χ����100000��RE
typedef long long ll;

int n, q, L, R, op;
ll k, P, a[N];

struct SegmentTree
{
    ll sum[N << 2], mtp[N << 2], inc[N << 2];

    void down(int rt, int l, int r)
    {
        if (mtp[rt] == 1 && inc[rt] == 0) return; //��Ϊ��ʼ״̬ʱ�����´�
        if (l != r)
            mtp[lson] = mtp[lson] * mtp[rt] % P, //���ӵ�mtp���Ե�ǰ�ڵ�mtp
            mtp[rson] = mtp[rson] * mtp[rt] % P, 
            inc[lson] = (inc[lson] * mtp[rt] % P + inc[rt]) % P; //���ӵ�inc���Ե�ǰ�ڵ�mtp�ټӵ�ǰ�ڵ�inc
            inc[rson] = (inc[rson] * mtp[rt] % P + inc[rt]) % P;
        sum[rt] = (sum[rt] * mtp[rt] % P + inc[rt] * (r - l + 1) % P) % P; //���½ڵ���Ϣ
        mtp[rt] = 1, inc[rt] = 0; //��ձ��
    }

    void build(int rt, int l, int r) //�������鹹���߶�������Ȼ��insertҲ�ǿ��Ե�
    {
        mtp[rt] = 1, inc[rt] = 0; //��ʼ�����
        if (l == r) { sum[rt] = a[l]; return; }
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        sum[rt] = sum[lson] + sum[rson];
    }

    ll qrysum(int rt, int l, int r)
    {
        down(rt, l, r); //���´����
        if (L <= l && r <= R) return sum[rt];
        ll ret = 0; int mid = l + r >> 1;
        if (L <= mid) ret = (ret + qrysum(lson, l, mid)) % P;
        if (mid + 1 <= R) ret = (ret + qrysum(rson, mid + 1, r)) % P;
        return ret;
    }

    void rangeplus(int rt, int l, int r)
    {
        down(rt, l, r); //���´����
        if (L <= l && r <= R) { inc[rt] = (inc[rt] + k) % P; return; } //������£�inc����k
        int mid = l + r >> 1;
        if (L <= mid) rangeplus(lson, l, mid);
        if (mid + 1 <= R) rangeplus(rson, mid + 1, r);
        down(lson, l, mid), down(rson, mid + 1, r); //�´����ӵı��
        sum[rt] = (sum[lson] + sum[rson]) % P;
    }

    void rangemtp(int rt, int l, int r)
    {
        down(rt, l, r); //���´����
        if (L <= l && r <= R) { mtp[rt] = mtp[rt] * k % P, inc[rt] = inc[rt] * k % P; return; } //������£�mtp��inc������һ��k
        int mid = l + r >> 1;
        if (L <= mid) rangemtp(lson, l, mid);
        if (mid + 1 <= R) rangemtp(rson, mid + 1, r);
        down(lson, l, mid), down(rson, mid + 1, r); //�´����ӵı��
        sum[rt] = (sum[lson] + sum[rson]) % P;
    }
} tree;

inline ll read() //�������
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

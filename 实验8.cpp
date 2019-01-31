#include<bits/stdc++.h>
using namespace std;

int a[10001], b[10001], c[10001], ans[1000001], tot[1000001], qwq[1000001]; 
int n, lenans = 0, lentot = 1, lenqwq;

struct info
{
    int a, b, c;
}p[1001];

bool cmp(const info & u, const info & v) 
{
    return u.c < v.c;
}

void Cross(int x)
{
    int add = 0;
    for(int i = 1; i <= lentot; i++)
    {
        tot[i] *= x;
        tot[i] += add; 
        add = (tot[i] / 10);
        tot[i] %= 10;
    }
    while(add > 0)
    {
        lentot++;
        tot[lentot] = add;
        add = add / 10;
        tot[lentot] %= 10;
    }
}

void Deco(int y)
{
    memset(qwq, 0, sizeof(qwq));
    int tmp = 0;
    lenqwq = 0;
    for(int i = lentot; i >= 1; i--)
    {
        tmp *= 10;
        tmp += tot[i];
        qwq[i] = tmp / y;
        if(lenqwq == 0 && qwq[i] != 0)
            lenqwq = i;
        tmp %= y;
    }
}

bool larger()
{
    if(lenans < lenqwq)
        return 1;
    if(lenans > lenqwq)
        return 0;
    int q = lenans;
    while(ans[q] == qwq[q] && q > 1)
        q--;
    if(ans[q] < qwq[q])
        return 1;
    return 0;
}

void swapansqwq()
{
    lenans = lenqwq;
    for(int i = 1; i <= lenqwq; i++)
        ans[i] = qwq[i];
}

int main()
{
    cin >> n;
    for(int i = 0; i <= n; i++)
    { 
        scanf("%d %d", &p[i].a, &p[i].b);
        p[i].c = p[i].a * p[i].b;
    } 
    sort(p+1, p+n+1, cmp);
    tot[0] = tot[1] = 1;
    for(int i = 1; i <= n; i++)
    {
        Cross(p[i-1].a);
        Deco(p[i].b);
        if(larger())
            swapansqwq();
    }
    for(int i = lenans; i >= 1; i--)
        printf("%d", ans[i]);
    return 0;
}


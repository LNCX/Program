#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 5, maxm = maxn << 1, inf = maxn;
int head[maxm], nxt[maxm], v[maxm], cnt, root;
int dp[maxn][3];
int n, opt;

inline void addline(int x, int y) { v[cnt] = y, nxt[cnt] = head[x], head[x] = cnt++; }

inline void dfs(int x, int f)
{
    dp[x][0] = 1, dp[x][1] = 0, dp[x][2] = inf;
    for (int i = head[x]; ~i; i = nxt[i])
        if (v[i] != f)
        {
            dfs(v[i], x);
            dp[x][0] += min(dp[v[i]][0], dp[v[i]][1]);
            dp[x][1] += dp[v[i]][2];
        }
    for (int i = head[x]; ~i; i = nxt[i])
        if (v[i] != f)
            dp[x][2] = min(dp[x][2], dp[x][1] + dp[v[i]][0] - dp[v[i]][2]);
    return;
}

signed main(void)
{
    while (true)
    {
        memset(head, -1, sizeof head);
        cnt = 0;

        scanf("%d", &n);
        for (int i = 1, x, y; i < n; i++)
            scanf("%d %d", &x, &y), addline(x, y), addline(y, x);

        root = rand() % n + 1, dfs(root, 0);
        printf("%d\n", min(dp[root][0], dp[root][2]));

        scanf("%d", &opt);
        if (opt == -1)
            break;
    }
    return 0;
}

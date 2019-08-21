#include<bits/stdc++.h>
const int N=110, INF=3e8, M=1e6 + 10;
inline void gugu(int& h, int f)
{
    if(h > f)
        h=f;
}
int n, m, ans=0, q[M];
int f[N][N];
void floyd()
{
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;++j)
                if(i != j and k != i and k != j)
                        gugu(f[i][j], f[i][k] + f[k][j]);
}
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;++j)
        {
            scanf("%1d", &f[i][j]);
            if(f[i][j] == 0)
                f[i][j]=INF;
        }
    floyd();
    scanf("%d", &m);
    int s, t=1;scanf("%d", &s);
    q[++ans]=s;
    for(int i=2, that=s;i<=m;i++)
    {
        int x;
        scanf("%d", &x);
        while (i - t != f[s][x])
        {
            q[++ans]=that;
            s=that;t=i - 1;
        }
        if(i == m)
            q[++ans]=x;
        that=x;
    }
    printf("%d\n", ans);
    for(int i=1;i<=ans;i++)
        printf("%d ", q[i]);
    return 0;
}
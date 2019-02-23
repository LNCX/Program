#include<bits/stdc++.h>
#define maxn 25
#define mod 1000000007
struct mat 
{
	int a[maxn][maxn];
}now;
bool bz[maxn][maxn];
int n, m, q, last;
const int D[4][2] = 
{ { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
inline int calc(int x, int y)
{
	return (x - 1) * m + y;
}
mat mul(mat x,mat y)
{
	mat z;
	memset(z.a, 0, sizeof(z.a));
	for (int i = 1; i <= n * m; ++i)
		for (int k = 1; k <= n * m; ++k)
			for (int j = 1; j <= n * m; ++j)
				z.a[i][j] = (z.a[i][j] + x.a[i][k] * 1ll * y.a[k][j]) % mod;
	return z;
}
mat pow(mat x, int y) 
{
	mat ret;
	memset(ret.a, 0, sizeof(ret.a));
	for (int i = 1; i <= n * m; ++i) ret.a[i][i] = 1;
	for (; y; y >>= 1, x = mul(x, x)) if (y & 1) ret = mul(ret, x);
	return ret;
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	last = 1;
	for (int i = 1; i <= n * m; ++i) now.a[i][i] = 1;
	while (q--) 
    {
		int tp,x,y,t;
		scanf("%d%d%d%d", &tp, &x, &y, &t);
		mat tmp;
		memset(tmp.a, 0, sizeof(tmp.a));
		for (int i = 1; i <= n; ++i) 
        {
			for (int j = 1; j <= m; ++j) 
            {
				for (int k = 0; k < 4; ++k) 
                {
					int xx = i + D[k][0], yy = j + D[k][1];
					if (xx <= 0 || yy <= 0 || xx > n || yy > m) continue;
					if (bz[i][j] || bz[xx][yy]) tmp.a[calc(i, j)][calc(xx, yy)] = 0;
					else tmp.a[calc(i, j)][calc(xx, yy)] = 1;
				}
				if (bz[i][j]) tmp.a[calc(i, j)][calc(i, j)] = 0;
				else tmp.a[calc(i, j)][calc(i, j)] = 1;
			}
		}
		now = mul(now, pow(tmp, t - last));
		if (tp == 1) printf("%d\n", now.a[1][calc(x, y)]);
		if (tp == 2) bz[x][y] = 1;
		if (tp == 3) bz[x][y] = 0;
		last = t;
	}
	return 0;
}
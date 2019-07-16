#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

typedef long long LL;

const int MAXM = 2e5 + 10;
const LL INF = 1e18;

int n, m;
LL A, B, C;

struct Edge {
	int u, v, t1, t2;
	LL res;
} edge[MAXM];
struct Ques {
	int t, id;
} que[MAXM];

struct QY666 {
	std::vector <int> v;
	int l, r;
	#define X(i) (2 * A * edge[i].t2)
	#define Y(i) (edge[i].res + A * edge[i].t2 * edge[i].t2 - B * edge[i].t2)
	QY666() {
		l = 0, r = -1;
	}
	inline void add(int x) {
		for (; l < r && (Y(v[r]) - Y(v[r - 1])) * (X(x) - X(v[r])) >= (Y(x) - Y(v[r])) * (X(v[r]) - X(v[r - 1])); --r) v.pop_back();
		v.push_back(x), ++r;
	}
	inline LL ask(int x) {
		for (; l < r && (Y(v[l + 1]) - Y(v[l])) <= (X(v[l + 1]) - X(v[l])) * edge[x].t1; ++l);
		return Y(v[l]) - edge[x].t1 * X(v[l]) + A * edge[x].t1 * edge[x].t1 + B * edge[x].t1 + C;
	}
	#undef X
	#undef Y
} Q[100010];

inline bool cmp1(Edge a, Edge b) {
	return a.t1 < b.t1;
}

inline bool cmp2(Ques a, Ques b) {
	return a.t < b.t;
}

int main() {
	freopen("route.in", "r", stdin); freopen("route.out", "w", stdout);
	scanf("%d%d%lld%lld%lld", &n, &m, &A, &B, &C);
	for(int i = 1; i <= m; ++i) scanf("%d%d%d%d", &edge[i].u, &edge[i].v, &edge[i].t1, &edge[i].t2);
	std::sort(edge + 1, edge + 1 + m, cmp1);
	for(int i = 1; i <= m; ++i) que[i].t = edge[i].t2, que[i].id = i;
	std::sort(que + 1, que + 1 + m, cmp2);
	edge[0].res = 1e9, Q[1].add(m + 1);
	for (int i = 2; i <= n; ++i) Q[i].add(0);
	for (int i = 1, j = 1; i <= m; ++i) {
		for (; j <= m && que[j].t <= edge[i].t1; ++j) Q[edge[que[j].id].v].add(que[j].id);
		edge[i].res = Q[edge[i].u].ask(i);
	}
	LL res = INF;
	for (int i = 1; i <= m; i++) edge[i].v == n && (res = std::min(res, edge[i].t2 + edge[i].res));
	printf("%lld\n", res);
	fclose(stdin); fclose(stdout);
	return 0;
}
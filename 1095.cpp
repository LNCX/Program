#include <cstdio>
#include <cstdlib>

struct object
{
	int id;
	int v;
	int m;
};

int cmp(const void *a, const void *b)
{
	struct object *aa, *bb;
	aa = (struct object *) a;
	bb = (struct object *) b;
	if (aa->v != bb->v)
	   return bb->v - aa->v;
	else
		return aa->m - bb->m;
}

int main()
{
//	freopen("in.txt", "r", stdin);
	int n, i;
	struct object ob[1000];
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &((ob+i)->v), &((ob+i)->m));
		(ob+i)->id = i+1;	
	}
	qsort(ob, n, sizeof(ob[i]), cmp);
	for (i=0; i<n; i++)
		printf("%d ", (ob+i)->id);
	return 0;
}

#include <stdio.h>
char a[1001][1001];
void small(char *s)
{
	char b,*f;
	f = s;
	int c;
		c = 1;
		while (s[c])
		{
			while (*(s+c))
			{
				if (*s > *(s + 1))
				{
					b = *(s + 1);
					*(s + 1) = *s;
					*s = b;

				}
		
				s++;
			}
			c++;
			s = f;
		}
	
	
}
bool strless(char *a, char *b)
{
	for (; *a||*b;)
	{
		if (*a < *b)
		{
			return true;
		}
		else if(*a==*b)
		{
			a++;
			b++;
		}
		else
		{
			return false;
		}
	}
	if (*a == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int n;




	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", &a[i][0]);
		small(&a[i][0]);

		
	}
	char *c;
	c = &a[1][0];
	for (int i = 2; i <= n; i++)
	{
		if (strless(&a[i][0], c))
			{
				c = &a[i][0];
			}
	}

	printf("%s\n", c);
}

#include <cstdio>  
#include <cstring>  
#define N 500
#define BASE 10  
using namespace std;
char f1[N], f2[N], temp[N];  
int len;  
  
int main(void)  
{  
    int n, sum, c, i, j;  
    scanf("%d", &n);  
    if(n <= 2) 
	{  
        printf("1\n");  
        return 0;  
    } 
    memset(f1, 0, sizeof(f1));  
    memset(f2, 0, sizeof(f2));  
    memset(temp, 0, sizeof(temp));  
    len = 1;  
    f1[0] = 1;  
    f2[0] = 1;  
    for(i=3; i<=n; i++) 
	{  
        c = 0;  
        for(j=0; j<len; j++) 
		{  
            sum = c + 2 * f1[j] + 3 * f2[j];  
            temp[j] = sum % BASE;  
            c = sum / BASE;  
        }  
        while(c > 0) 
		{  
            temp[len++] = c % BASE;  
            c /= BASE;  
        }  
        memcpy(f1, f2, len);  
        memcpy(f2, temp, len);  
    }  
    for(i=len-1; i>=0; i--)  
        printf("%d", f2[i]);  
    printf("\n");  
    return 0;  
}  

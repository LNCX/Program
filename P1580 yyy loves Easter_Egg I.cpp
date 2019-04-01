#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int c = 1;
char s[maxn],name[maxn],a[maxn],t[maxn];
int main()
{
    gets(s);                    
    sscanf(strstr(s, "@"), "@yyy loves %s", name);                    
    while(c++)
    {
        gets(s);
        int len=strlen(s);
        if(len== 1) break;
        sscanf(s, "yyy loves %s",a);                
        if(!strcmp(a, name))
        {                    
            printf("Successful @yyy loves %s attempt\n",name);
            return 0;
        }
        if(count(s, s+len, '@') != 1 || (sscanf(strstr(s, "@"), "@yyy loves %s", t), strcmp(t, name)))
        {
            printf("Unsuccessful @yyy loves %s attempt\n", name);
            printf("%d\n", c);
            printf("yyy loves %s\n", a);                    
            return 0;
        }
    }
    printf("Unsuccessful @yyy loves %s attempt\n", name);
    printf("%d\n", c-1);
    printf("Good Queue Shape\n");
    return 0;
}
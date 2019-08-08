#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
char str[2][N];
int main()
{
    int t;
    scanf("%s", str[0]);
    scanf("%s", str[1]);
    int len = strlen(str[0]);
    int ans = 0;
    for(int i = 0; i < len; i++)
    {
        if(str[0][i] == '0' && str[1][i] == '0')
        {
            if(i-1 >= 0 && str[0][i-1] == '0')
            {
                str[0][i-1] = 'X';
                str[0][i] = 'X';
                str[1][i] = 'X';
                ans++;
            }
            else if(i-1 >=0&&str[1][i-1]=='0')
            {
                str[1][i-1] = 'X';
                str[0][i] = 'X';
                str[1][i] = 'X';
                ans++;
            }
            else if(str[0][i+1] == '0')
            {
                str[0][i+1] = 'X';
                str[0][i] = 'X';
                str[1][i] = 'X';
                ans++;
            }
            else if(str[1][i+1] == '0')
            {
                str[1][i+1] = 'X';
                str[0][i] = 'X';
                str[1][i] = 'X';
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

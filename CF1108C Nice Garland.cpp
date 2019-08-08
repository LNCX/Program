#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,len=0x7fffffff,type;
char a[N];
char ans[6][3]=
{
    {'R','G','B'},
    {'R','B','G'},
    {'B','R','G'},
    {'B','G','R'},
    {'G','B','R'},
    {'G','R','B'}
};
int main()
{
    scanf("%d%s",&n,a);
    for(int i=0;i<6;i++)
    {
        int mid=0;
        for(int j=0;j<n;j++)
        {
            if(ans[i][j%3]!=a[j])
                mid++;
        }
        if(mid<len)
        {
            len=mid;
            type=i;
        }
    }
    cout<<len<<endl;
    for(int i=0;i<n;i++)
        printf("%c",ans[type][i%3]);
    puts("");
    return 0;
}
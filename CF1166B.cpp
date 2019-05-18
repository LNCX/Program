#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    for(int n=1;n*n<=k;n++)
        if(k%n==0&&n>=5&&k/n>=5)
        {
            int m=k/n;
            char s[]={'a','e','i','o','u'};
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    printf("%c",s[(i+j)%5]);
            return 0;
        }
    puts("-1");
    return 0;
}
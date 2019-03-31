#include<bits/stdc++.h>
using namespace std;
int s[50][50];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=3*n;i++)
        for(int j=1;j<=3*n;j++)
            s[i][j]=-1;
    int mid=n+1;
    for(int i=1;i<=n+1;i++)
    {
        int cnt=i-2;
        for(int j=mid-1;j>=1&&cnt>=0;j--)
            s[i][j]=cnt--;
        s[i][mid]=i-1;
        cnt=i-2;
        for(int j=mid+1;j<=2*n+1&&cnt>=0;j++)
            s[i][j]=cnt--;
    }
    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<mid+i-1;j++)
            if(s[i][j]==-1) putchar(' '),putchar(' ');
            else cout<<s[i][j]<<" ";
        cout<<s[i][mid+i-1];
        puts("");
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<mid+i-1;j++)
            if(s[i][j]==-1) putchar(' '),putchar(' ');
            else cout<<s[i][j]<<" ";
        cout<<s[i][mid+i-1];
        puts("");
    }        
    return 0;
}
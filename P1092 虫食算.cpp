#include<bits/stdc++.h>
using namespace std;
int n,a[4][30];
int add[30],num[30],used[30];
void print()
{
    for(int i=0;i<n;i++)
        printf("%d ",num[i]);
    printf("\n");
    exit(0);
}
bool cut()
{
	 for(int i=1;i<=n;i++)
    {
    	int A=num[a[1][i]],B=num[a[2][i]],C=num[a[3][i]];
    	if(A==-1||B==-1||C==-1) continue;
        else if((A+B+1)%n!=C&&(A+B)%n!=C) return false;
    }
    return true;
}
bool judge(int y)
{
    int A=num[a[1][y]],B=num[a[2][y]],C=num[a[3][y]];
    if((A+B+add[y])%n!=C) return false;
    return true;
}
void dfs(int x,int y)
{
	if(!cut()) return;
    if(y>n)
    {
        if(add[y]==0)
            print();
        return;
    }
    if(x==1&&y>1&&!judge(y-1))
        return;
    if(num[a[x][y]]!=-1)
    {
        if(x==3)
        {
            add[y+1]=(num[a[1][y]]+num[a[2][y]]+add[y])/n;
            dfs(1,y+1);
            add[y+1]=0;
        }
        else dfs(x+1,y);
    }
    else 
    	for(int i=0;i<n;i++)
            if(!used[i])
            {
                used[i]=1;
                num[a[x][y]]=i;
                if(x==3)
                {
                    add[y+1]=(num[a[1][y]]+num[a[2][y]]+add[y])/n;
                    dfs(1,y+1);
                    add[y+1]=0;
                }
                else dfs(x+1,y);
                used[i]=0;
                num[a[x][y]]=-1;			
            }
}
int main()
{
    cin>>n;
    for(int i=1;i<=3;i++)
    {
        char s[30];
        scanf("%s",s);
        int len=strlen(s);
        for(int j=0;j<len;j++)
            a[i][len-j]=s[j]-'A';
    }
    for(int i=0;i<n;i++)
    {
        add[i]=0;
        num[i]=-1;
        used[i]=0;
    }
    add[1]=0;
    dfs(1,1);
    return 0;
}

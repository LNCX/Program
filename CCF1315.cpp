#include<cstdio>
int n,i[15];
void DFS(int t) 
{
    if (t/2==1) 
    {
          printf("2");
          if (t-2)
          {
              printf("+");
                DFS(t-2);
          }
    }
    else
    {
          printf("2(");
          int num=0;
        for (int a=0;a<=15;a++)
            if (i[a]>t)
            {
            num=a-1;
            break;
          }
        if (num>2)
        {
                DFS(num);
                printf(")");
          }
        else
            printf("%d)",num);
        if (t-i[num])
        {
            printf("+");
              DFS(t-i[num]);
        }
    }
}
int main()
{
    scanf("%d",&n);
    i[0]=1;
    for (int a=1;a<=15;a++)
      i[a]=i[a-1]*2;
    DFS(n);
    return 0;
}

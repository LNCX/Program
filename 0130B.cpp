#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,ret;
    cin >> n >> k;
    if (n % 2) ret = (n + 1) / 2 + (n - 1) / 2 * n;
    else ret = n * n / 2;
    if (k > ret) cout << "NO\n";
    else
    {
        cout << "YES\n";
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if (i % 2 == j % 2)
                {
                    if (k)
                    {
                        cout << "L";
                        k--;
                    }
                    else cout << "S";
                }
                else cout << "S";
            }
            cout << "\n";           
        }
    } 
    return 0;
}
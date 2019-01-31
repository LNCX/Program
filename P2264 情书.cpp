#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300001;
set<string> key, happen;
int n;
int ans = 0;
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        key.insert(s);
    }
    char c = getchar();
    string now;
    while (scanf("%c", &c) == 1)
    {
        if ((c >='a'&& c <='z') || (c >='A'&& c <='Z'))
        {
            if (c >='a'&& c <='z')
                c = c +'A'-'a';
            now += c;
        }
        else
        {
            if (!now.empty())
            {
                if (key.find(now) != key.end())
                    happen.insert(now);
                now.clear();
            }
            if (c =='.')
            {
                ans += happen.size();
                happen.clear();
            }
        }
    }
    printf("%d", ans);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
namespace Mker
{
#define uint unsigned int
    uint sd;
    int op;
    inline void init() { scanf("%u%d", &sd, &op); }
    inline uint uint_rand()
    {
        sd ^= sd << 13;
        sd ^= sd >> 7;
        sd ^= sd << 11;
        return sd;
    }
    inline double get_n()
    {
        double x = (double)(uint_rand() % 100000) / 100000;
        return x + 4;
    }
    inline double get_k()
    {
        double x = (double)(uint_rand() % 100000) / 100000;
        return (x + 1) * 5;
    }
    inline void read(double& n, double& a, double& b)
    {
        n = get_n();
        a = get_k();
        if(op)
            b = a;
        else
            b = get_k();
    }
#undef uint
}  // namespace Mker
double n, a, b, sum;
int main()
{
    int t;
    scanf("%d", &t);
    Mker::init();
    while(t--)
    {
        Mker::read(n, a, b);
        sum += 1.0 / (a * pow(n, a - 1) + b * pow(n, b - 1));
    }
    printf("%.6lf\n", sum);
    return 0;
}
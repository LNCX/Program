#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int c[1001][1001];
int b[1001][1001];
char zx[101];
void zh(char a) {
    if(a == 'A') {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                b[j][n - i + 1] = c[i][j];
            }
        }
    }//???????90??

    if(a == 'B') {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                b[m - j + 1][i] = c[i][j];
            }
        }
    }//????????90??

    if(a == 'C') {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                b[i][m - j + 1] = c[i][j];
            }
        }
    }//??????

    if(a == 'D') {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                b[n - i + 1][j] = c[i][j];
            }
        }
    }//???¡¤??

    memcpy(c, b, sizeof(c));

    if(a == 'A' || a == 'B')swap(m, n);
}
int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }

    scanf("%s", &zx);

    for(int i = 0; i < strlen(zx); i++) {
        zh(zx[i]);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << c[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

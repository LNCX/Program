#include<bits/stdc++.h>
using namespace std;
#define print(x) cout << (x) << '\n'
    
int main(){
    char c; cin >> c;
    string str = "OPKL";
    for (auto x : str){
    if (x == c) {print("Right"); return 0;}
    }
    print("Left");
    
    return 0;
}
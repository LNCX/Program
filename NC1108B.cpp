#include <bits/stdc++.h>
using namespace std;
int num;  
int ans; 
string binary; 
string temp; 
int main() {
	cin >> num;
	while(num) { 
		binary = (char)(num % 2 + '0') + binary;
		num /= 2;
	}
	for(int i = binary.length(); i < 8; i++) {
		binary = '0' + binary;
	}
	for(int i = 4; i < 8; i++) {
		temp += binary[i];
	}
	binary = temp + binary;
	for(int i = 0; i < 8; i++) {
		ans += (binary[i] - '0') * pow(2, 8 - i -1);
	}
	cout << ans;
	return 0;
}
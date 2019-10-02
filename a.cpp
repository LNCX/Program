 #include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define ll long long int
using namespace std;
 
int main() {
	// your code goes here
	
		ll n,k; cin >> n >> k;
	vector<ll> v(n,0);
	for(ll i=0;i<n;i++)
	cin >> v[i];
	queue<ll> q;
	unordered_set<ll> s;
	for(ll i=0;i<n;i++){
		if(q.size()<k){
			if(s.count(v[i])==0){
				s.insert(v[i]);
				q.push(v[i]);
			}
		}else{
		if(s.count(v[i])==0){
			ll topo = q.front();
			s.erase(topo);
			s.insert(v[i]);
			q.push(v[i]);
			q.pop();
		}	
		}
	}
	cout << q.size() << endl;
	stack<ll> st;
	while(!q.empty()){
		st.push(q.front());
		q.pop();
	}
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}
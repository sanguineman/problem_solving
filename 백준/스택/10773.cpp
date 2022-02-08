#include <bits/stdc++.h>  
using namespace std; 	
using ll = long long;  
const int INF = 5e5;  
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	int K;
	long long ans = 0;
	stack <int> sk;
	cin >> K;
	while(K--){
		int n;
		cin >> n;
		if(!n){
			sk.pop();
		}
		else{
			sk.push(n);
		}
	} 
	while(!sk.empty()){
		ans += sk.top();
		sk.pop();
	}
	cout << ans << '\n';
}

#include <bits/stdc++.h>  
using namespace std; 	
using ll = long long;  
const int INF = 5e5;  
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	stack <int> sk;
	string st;
	int N;
	cin >> N;
	while(N--){
		cin>> st;
		if(st == "push"){
			int n;
			cin >> n;
			sk.push(n);
		}
		else if(st == "pop"){
			if(!sk.empty()){
				cout << sk.top() << '\n';
				sk.pop();
			}
			else{
				cout << -1 << '\n';
			}
		}
		else if(st == "size"){
			cout << sk.size() << '\n';
		}
		else if(st == "empty"){
			if(!sk.empty()){
				cout << 0 << '\n';
			}			
			else{
				cout << 1 << '\n';
			}
		}
		else{
			if(!sk.empty()){
				cout << sk.top() << '\n';
			}
			else{
				cout << -1 << '\n';
			}
		}
	}
}

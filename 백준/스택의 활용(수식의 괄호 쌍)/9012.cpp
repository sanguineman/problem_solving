#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		string st;
		stack <char> sk;
		bool isValid = true;
		cin >> st;
		for(auto & s : st){
			if(s == '('){
				sk.push(s);
			}
			else if(s == ')'){
				if(sk.empty() || sk.top() != '('){
					isValid = false;
					break;
				}
				else{
					sk.pop();
				}
			}
		}
		if(!sk.empty())
			isValid = false;
		cout << (isValid ? "YES" : "NO") << '\n'; 
	}
}

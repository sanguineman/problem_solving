#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int N, ans = 0;
	cin >> N;
	while(N--){
		string st;
		bool isValid = true;
		stack <char> sk;
		cin >> st;
		for(auto & s : st){
			if(sk.empty())
				sk.push(s);
			else{
				if(sk.top() == s){
					sk.pop();
				}
				else{
					sk.push(s);
				}
			}
		}
		if(!sk.empty())
			isValid = false;
		if(isValid)
			ans++;
	}
	cout << ans << '\n';
}

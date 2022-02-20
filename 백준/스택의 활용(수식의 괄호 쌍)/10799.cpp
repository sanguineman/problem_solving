#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int ans = 0;
	stack <char> sk;
	string st;
	cin >> st;
	for(int i = 0; i < st.size(); i++){
		if(st[i] == '(')
			sk.push(st[i]);
		else{
			sk.pop();
			if(st[i-1] == '('){
				ans += sk.size();
			}
			else{
				ans++;
			}
		}
	}
	cout << ans << '\n';
}

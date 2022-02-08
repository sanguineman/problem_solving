#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, pos = 1, idx = 1;
	stack <int> sk;
	char ans[200001];
	cin >> n;
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		if(pos <= k){
			while(pos <= k){
				sk.push(pos);
				pos++;
				ans[idx++] = '+';
			}
			sk.pop();
			ans[idx++] = '-';
		}
		else if(!sk.empty() && sk.top() > k){
			cout << "NO" << '\n';
			return 0;
		}
		else if(!sk.empty() && sk.top() == k){
			sk.pop();
			ans[idx++] = '-';
		}
	}
	for(int i = 1; i <= n * 2 ; i++){
		cout << ans[i] << '\n';
	}
}

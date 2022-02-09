#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int N, seq[1000001], ans[1000001];
	stack <int> num;
	num.push(1000001);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> seq[i];
	}
	for(int i = N; i >= 1; i--){
		if(num.top() <= seq[i]){
			while(num.top() <= seq[i]){
				num.pop();
			}
		}
		if(num.top() == 1000001)
			ans[i] = -1;
		else
			ans[i] = num.top();
		num.push(seq[i]);
	}
	for(int i = 1; i <= N; i++){
		cout << ans[i] << ' ';
	}
}

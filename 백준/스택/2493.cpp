#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int N;
	stack <pair<int,int>> sk;
	sk.push({100000001,0});
	cin >> N;
	for(int i = 1; i <= N ; i++){
		int n;
		cin >> n;
		if(sk.top().first < n){
			while(sk.top().first < n){
				sk.pop();
			}
		}
		cout << sk.top().second << ' ';
		sk.push({n,i});
	}
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int N;
	cin >> N;
	queue <int> que;
	while(N--){
		string st;
		cin >> st;
		if(st == "push"){
			int n;
			cin >> n;
			que.push(n);
		}
		else if(st == "pop"){
			if(que.empty()){
				cout << -1 << '\n';
			}
			else{
				cout << que.front() << '\n';
				que.pop();
			}
		}
		else if(st == "size"){
			cout << que.size() << '\n';
		}
		else if(st == "empty"){
			if(que.empty()){
				cout << 1 << '\n';
			}
			else{
				cout << 0 << '\n';
			}
		}
		else if(st == "front"){
			if(que.empty()){
				cout << -1 << '\n';
			}
			else{
				cout << que.front() << '\n';
			}
		}
		else if(st == "back"){
			if(que.empty()){
				cout << -1 << '\n';
			}
			else{
				cout << que.back() << '\n';
			}
		}
	}
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int N;
	deque <int> deq;
	cin >> N;
	while(N--){
		string st;
		int n;
		cin >> st;
		if(st == "push_front"){
			cin >> n;
			deq.push_front(n);
		}
		else if(st == "push_back"){
			cin >> n;
			deq.push_back(n);
		}
		else if(st == "pop_front"){
			if(deq.size()){
				cout << deq.front() << '\n';
				deq.pop_front();
			}
			else
				cout << -1 << '\n';
			
		}
		else if(st == "pop_back"){
			if(deq.size()){
				cout << deq.back() << '\n';
				deq.pop_back();
			}
			else
				cout << -1 << '\n';
		}
		else if(st == "size"){
			cout << deq.size() << '\n';
		}
		else if(st == "empty"){
			cout << (deq.empty() ? 1 : 0) << '\n';
		}
		else if(st == "front"){
			if(deq.size())
				cout << deq.front() << '\n';
			else
				cout << -1 << '\n';
		}
		else if(st == "back"){
			if(deq.size())
				cout << deq.back() << '\n';
			else
				cout << -1 << '\n';
		}
	}
}

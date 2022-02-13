#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int N;
	queue <int> que;
	cin >> N;
	for(int i = 1; i <= N; i++){
		que.push(i);
	}
	while(que.size() != 1){
		que.pop();
		if(que.size() == 1)
			break;
		else{
			que.push(que.front());
			que.pop();
		}
	}
	cout << que.front() << '\n';
}

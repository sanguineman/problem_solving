#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int N, M, ans = 0;
	deque <int> deq;
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		deq.push_back(i);
	}
	for(int i = 1; i <= M; i++){
		int pos;
		cin >> pos;
		for(int j = 0; j < deq.size(); j++){
			if(deq[j] == pos){
				if(deq.size() - j >= j){
					ans += j;
					for(int k = 0; k < j; k++){
						deq.push_back(deq.front());
						deq.pop_front();
					}
				}
				else{
					ans += (deq.size() - j);
					for(int k = 0; k < deq.size() - j; k++){
						deq.push_front(deq.back());
						deq.pop_back();
					}
				}
				deq.pop_front();
				break;
			}
		}
	}
	cout << ans << '\n';
}

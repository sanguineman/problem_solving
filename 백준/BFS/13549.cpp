#include <bits/stdc++.h> 
using namespace std; 
using ll = long long;  
const int INF = 5e5;  
int N, K, dist[100001];
deque <int> deq;
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> N >> K;
	fill(dist,dist+100001,-1);
	deq.push_back(N);
	dist[N] = 0;
	while(!deq.empty()){
		int cur = deq.front();
		deq.pop_front();
		if(cur == K){
			cout << dist[cur] << '\n';
			return 0;
		}
		for(const int & nx : {cur-1,cur+1,2*cur}){
			if(nx < 0 || nx > 100000)
				continue;
			if(dist[nx] != -1)
				continue;
			if(nx == 2 * cur){
				deq.push_front(nx);
				dist[nx] = dist[cur];
			}
			else{
				deq.push_back(nx);
				dist[nx] = dist[cur] + 1;
			}
		}
	}
}

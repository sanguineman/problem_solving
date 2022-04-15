#include <bits/stdc++.h>  
using namespace std; 
using ll = long long;  
const int INF = 5e5;  
int F, S, G, U, D;
int dist[1000001];
int dx[2];
queue <int> Q;
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> F >> S >> G >> dx[0] >> dx[1];
	Q.push(S);
	fill(dist,dist+F+1,-1);
	dist[S] = 0;
	while(!Q.empty()){
		auto cur = Q.front();
		Q.pop();
		for(int dir = 0; dir < 2; dir++){
			int nx = (dir == 0) ? (cur + dx[dir]) : (cur - dx[dir]);
			if(nx < 1 || nx > F)
				continue;
			if(dist[nx] >= 0)
				continue;
			Q.push(nx);
			dist[nx] = dist[cur] + 1;
		}
	}
	if(dist[G] >= 0)
		cout << dist[G];
	else
		cout << "use the stairs";  
}

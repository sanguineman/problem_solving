#include <bits/stdc++.h>  
using namespace std; 	
using ll = long long;  
const int INF = 5e5;  
#define X first
#define Y second
int N, K, cnt, pos[100001];
int mn = INT_MAX;
queue <pair<int,int>> Q;
bool visited[100001];
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> N >> K;
	Q.push({N,0});
	visited[N] = 1;
	while(!Q.empty()){
		auto cur = Q.front();
		Q.pop();
		if(cur.X == K){
			if(cur.Y < mn)
				mn = cur.Y;
		}
		for(int dir = 0; dir < 3; dir++){
			int npos;
			if(dir == 0)
				npos = cur.X - 1;
			else if(dir == 1 && cur.X + 1 <= K)
				npos = cur.X + 1;
			else if(cur.X * 2 <= K + 1)
				npos = cur.X * 2;
			if(npos < 0 || npos > 2 * max(N,K))
				continue;
			if(visited[npos])
				continue;
			visited[npos] = 1;
			Q.push({npos,cur.Y + 1});
		}
	}
	cout << mn << '\n';
}

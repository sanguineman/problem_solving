#include <bits/stdc++.h>  
using namespace std; 	
using ll = long long;  
#define X first
#define Y second
const int INF = 5e5; 
int N, M;
int mn = INT_MAX;
int board[101][101];
bool visited[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 
queue <pair<pair<int,int>,int>> Q;
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		string st;
		cin >> st;
		for(int j = 0; j < M; j++){
			board[i][j+1] = (st[j] - '0');
		}
	}
	Q.push({{1,1},1});
	visited[1][1] = 1;
	while(!Q.empty()){
		pair<pair <int,int>,int> cur = Q.front();
		Q.pop();
		if(cur.X.X == N && cur.X.Y == M){
			if(cur.second < mn)
				mn = cur.second;
		}
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X.X + dx[dir];
			int ny = cur.X.Y + dy[dir];
			if(nx <= 0 || nx > N || ny <= 0 || ny > M )
			continue;
			if(visited[nx][ny] || !board[nx][ny]){
				continue;
			
			}
			visited[nx][ny] = 1;
			Q.push({{nx,ny},cur.second + 1});
		}
	}
	cout << mn << '\n';
}

#include <bits/stdc++.h>  
using namespace std; 	
using ll = long long;  
const int INF = 5e5;  
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int T, M, N, K, board[51][51];
bool visited[51][51];
void bfs(int i, int j){
	queue <pair<int,int>> Q;
	Q.push({i,j});
	visited[i][j] = 1;
	while(!Q.empty()){
		auto cur = Q.front();
		Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if(visited[nx][ny] || !board[nx][ny])
				continue;
			Q.push({nx,ny});
			visited[nx][ny] = 1;
		}
	}
}
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> T;
	while(T--){
		cin >> M >> N >> K;
		while(K--){
			pair <int,int> pos;
			cin >> pos.X >> pos.Y;
			board[pos.Y][pos.X] = 1;
		}	
		int cnt = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(board[i][j] == 1 && !visited[i][j]){
					bfs(i,j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		memset(board,0,sizeof(board));
		memset(visited,0,sizeof(visited));
	}
}

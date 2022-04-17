#include <bits/stdc++.h>  
using namespace std; 
using ll = long long;  
const int INF = 5e5;  
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N, M, board[1001][1001];
int dist[2][1001][1001];
queue <pair<pair<int,int>,int>> Q;
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		string st;
		cin >> st;
		for(int j = 0; j < M; j++){
			board[i][j] = st[j] - '0';
		}
	}
	for(int k = 0; k < 2; k++){
		for(int i = 0; i < N; i++)
			fill(dist[k][i],dist[k][i]+M,-1);
	}
	Q.push({{0,0},0});
	dist[0][0][0] = 0;
	while(!Q.empty()){
		auto cur = Q.front();
		Q.pop();
		if(cur.X.X == N - 1 && cur.X.Y == M - 1){
			cout << dist[cur.Y][cur.X.X][cur.X.Y] + 1;
			return 0;
		}
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X.X + dx[dir];
			int ny = cur.X.Y + dy[dir];
			if(nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if(dist[cur.Y][nx][ny] >= 0 || (board[nx][ny] == 1 && cur.Y))
				continue;     
			if(board[nx][ny] == 1 && !cur.Y){
				Q.push({{nx,ny},1});
				dist[1][nx][ny] = dist[cur.Y][cur.X.X][cur.X.Y] + 1;
			}
			else{
				Q.push({{nx,ny},cur.Y});
				dist[cur.Y][nx][ny] = dist[cur.Y][cur.X.X][cur.X.Y] + 1;
			}
		}
	}
	cout << -1 << '\n';
}

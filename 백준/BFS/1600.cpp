#include <bits/stdc++.h> 
using namespace std; 
using ll = long long;  
const int INF = 5e5;  
#define X first
#define Y second
int dxM[4] = {1,0,-1,0};
int dyM[4] = {0,1,0,-1};
int dxH[8] = {-2,-1,1,2,2,1,-1,-2};
int dyH[8] = {1,2,2,1,-1,-2,-2,-1};
int K, W, H, board[201][201], dist[31][201][201];
queue <pair<pair<int,int>,int>> Q; 
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> K >> W >> H;
	for(int k = 0; k <= K; k++){
		for(int i = 0; i < H; i++)
			fill(dist[k][i],dist[k][i]+W,-1);
	}
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin >> board[i][j];
		}
	}
	dist[0][0][0] = 0;
	Q.push({{0,0},0});
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		if(cur.X.X == H - 1 && cur.X.Y == W - 1){
			cout << dist[cur.Y][cur.X.X][cur.X.Y] << '\n';
			return 0;
		}
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X.X + dxM[dir];
			int ny = cur.X.Y + dyM[dir];
			if(nx < 0 || nx >= H || ny < 0 || ny >= W)
				continue;
			if(dist[cur.Y][nx][ny] >= 0 || board[nx][ny])
				continue;
			Q.push({{nx,ny},cur.Y});
			dist[cur.Y][nx][ny] = dist[cur.Y][cur.X.X][cur.X.Y] + 1;
		}
		if(cur.Y >= K)
			continue;
		for(int dir = 0; dir < 8; dir++){
			int nx = cur.X.X + dxH[dir];
			int ny = cur.X.Y + dyH[dir];
			if(nx < 0 || nx >= H || ny < 0 || ny >= W)
				continue;
			if(dist[cur.Y+1][nx][ny] >= 0 || board[nx][ny])
				continue;
			Q.push({{nx,ny},cur.Y+1});
			dist[cur.Y+1][nx][ny] = dist[cur.Y][cur.X.X][cur.X.Y] + 1;
		}
	}
	cout << -1 << '\n';
	return 0;
}

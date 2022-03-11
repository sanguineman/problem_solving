#include <bits/stdc++.h>  
using namespace std; 	
using ll = long long;  
const int INF = 5e5;  
#define X first
#define Y second
#define Z third
int M, N, H, board[101][101][101];
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
bool visited[101][101][101];
queue <pair<tuple<int,int,int>,int>> Q;
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> M >> N >> H;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				cin >> board[i][j][k];
			}
		}
	}
	for(int i = 0; i < H; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				if(board[i][j][k] == 1){
					Q.push({make_tuple(i,j,k),0});
					visited[i][j][k] = 1;
				}
			}
		}
	}
	int mx = 0;
	while(!Q.empty()){
		auto cur = Q.front();
		Q.pop();
		bool check = false;
		for(int dir = 0; dir < 6; dir++){
			int nx = get<1>(cur.X) + dx[dir];
			int ny = get<2>(cur.X) + dy[dir];
			int nz = get<0>(cur.X) + dz[dir];
			if(nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
				continue;
			if(visited[nz][nx][ny] || board[nz][nx][ny] == -1)
				continue;
			check = true;
			Q.push({make_tuple(nz,nx,ny),cur.Y + 1});
			visited[nz][nx][ny] = 1;			
			board[nz][nx][ny] = 1;			
		}					
		if(!check){
			if(cur.Y > mx)
				mx = cur.Y;			
		}	
	}
	for(int i = 0; i < H; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				if(board[i][j][k] == 0){
					cout << -1 << '\n';
					return 0;
				}
			}
		}
	}
	cout << mx << '\n';
}

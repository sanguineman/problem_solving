#include <bits/stdc++.h> 
using namespace std; 
using ll = long long;  
const int INF = 5e5;  
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N, board[101][101], visited[101][101];
queue <pair<int,int>> Q1;
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	}
	int land = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(board[i][j] && !visited[i][j]){
				land++;
				Q1.push({i,j});
				board[i][j] = land;
				visited[i][j] = land;
				while(!Q1.empty()){
					auto cur = Q1.front();
					Q1.pop();
					for(int dir = 0; dir < 4; dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;
						if(visited[nx][ny] || !board[nx][ny])
							continue;
						Q1.push({nx,ny});
						visited[nx][ny] = land;
						board[nx][ny] = land;
					}
				}
			}
		}
	}
	for(int i = 0; i < N; i++)
		fill(visited[i],visited[i]+N,0);
	int ans = INT_MAX;
	for(int k = 1; k <= land; k++){
		queue <pair<pair<int,int>,int>> Q2;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(board[i][j] == k){
					for(int dir = 0; dir < 4; dir++){
						int nx = i + dx[dir];
						int ny = j + dy[dir];
						if(nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;
						if(board[nx][ny] == 0){
							Q2.push({{i,j},0});
							visited[i][j] = k;
							break;
						}
					}
				}
			}
		}
		int mn;
		bool check = false;
		while(!Q2.empty()){
			auto cur = Q2.front();
			Q2.pop();
			for(int dir = 0; dir < 4; dir++){
				int nx = cur.X.X + dx[dir];
				int ny = cur.X.Y + dy[dir];
				if(nx < 0 || nx >= N || ny < 0 || ny >= N)
					continue;
				if(visited[nx][ny] == k || board[nx][ny] == k)
					continue;
				if(board[nx][ny] != k && board[nx][ny] != 0){
					check = true;
					mn = cur.Y;
					break;
				}
				Q2.push({{nx,ny},cur.Y+1});
				visited[nx][ny] = k;
			}
			if(check)
				break;
		}
		while(!Q2.empty())
			Q2.pop();
		ans = min(mn, ans);
	}
	cout << ans << '\n';
}

#include <bits/stdc++.h>  
using namespace std; 	
using ll = long long;  
const int INF = 5e5;  
#define X first
#define Y second
char board[101][101];
bool visited[101][101];
int N, ans[2];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue <pair<int,int>> Q;
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> N;
	for(int i = 0; i < N; i++){
		string st;
		cin >> st;
		for(int j = 0; j < N; j++){
			board[i][j] = st[j];
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(!visited[i][j]){
				ans[0]++;
				Q.push({i,j});
				visited[i][j] = 1;
				while(!Q.empty()){
					auto cur = Q.front();
					Q.pop();
					for(int dir = 0; dir < 4; dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;
						if(visited[nx][ny])
							continue;
						if(board[cur.X][cur.Y] == board[nx][ny]){
							Q.push({nx,ny});
							visited[nx][ny] = 1;
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			visited[i][j] = 0;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(!visited[i][j]){
				ans[1]++;
				Q.push({i,j});
				visited[i][j] = 1;
				while(!Q.empty()){
					auto cur = Q.front();
					Q.pop();
					for(int dir = 0; dir < 4; dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;
						if(visited[nx][ny])
							continue;
						if(board[cur.X][cur.Y] == 'R' || board[cur.X][cur.Y] == 'G'){
							if(board[nx][ny] != 'B'){
								Q.push({nx,ny});
								visited[nx][ny] = 1;
							}
						}
						else{
							if(board[nx][ny] == 'B'){
								Q.push({nx,ny});
								visited[nx][ny] = 1;
							}
						}
					}
				}
			}
		}
	}
	cout << ans[0] << ' ' << ans[1] << '\n';
}

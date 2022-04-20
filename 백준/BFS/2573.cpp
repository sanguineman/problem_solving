#include <bits/stdc++.h>  
using namespace std; 
using ll = long long;  
const int INF = 5e5;  
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N, M, ans, board[301][301];
bool visited[301][301];
queue <pair<int,int>> Q;
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> board[i][j];
		}
	}
	while(1){
		int div = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(board[i][j] && !visited[i][j]){
					div++;
					if(div > 1){
						cout << ans << '\n';
						return 0;
					}
					Q.push({i,j});
					visited[i][j] = 1;
					while(!Q.empty()){
						auto cur = Q.front();
						Q.pop();
						int cnt = 0;
						for(int dir = 0; dir < 4; dir++){
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if(nx < 0 || nx >= N || ny < 0 || ny >= M)
								continue;
							if(visited[nx][ny])
								continue;
							if(!board[nx][ny]){
								cnt++;
								continue;
							}
							Q.push({nx,ny});
							visited[nx][ny] = 1;
						}
						board[cur.X][cur.Y] = max(0, board[cur.X][cur.Y] - cnt);
					}
				}
			}
		}
		if(!div){
			cout << 0 << '\n';
			break;
		}
		for(int i = 0; i < N; i++)
			fill(visited[i],visited[i]+M,0);
		ans++;
	}	
}

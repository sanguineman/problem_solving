#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define X first
#define Y second
const int INF = 5e5;

int board[505][505];
bool vis[505][505];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int mx, n, m, cnt;

int bfs(int x, int y){
	int area = 1;
	queue <pair<int,int>> Q;
	Q.push({x,y});
	vis[x][y] = true;
	while(!Q.empty()){
		pair <int,int> cur = Q.front();
		Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if(!board[nx][ny] || vis[nx][ny])
				continue;
			vis[nx][ny] = true;
			Q.push({nx,ny});
			area++;
		}
	}
	return area;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] && !vis[i][j]){
				mx = max(bfs(i,j),mx);
				cnt++;
			}
		}
	}
	cout << cnt << '\n' << mx << '\n';
}

#include <bits/stdc++.h>  
using namespace std; 	
using ll = long long;  
const int INF = 5e5;  
#define X first
#define Y second
int m, n, mx, board[1001][1001];
bool visited[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue <pair<pair<int,int>,int>> Q;
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> m >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	} 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == 1){
				Q.push({{i,j},0});
				visited[i][j] = 1;
			}
		}
	}
	while(!Q.empty()){
		pair<pair<int,int>,int> cur = Q.front();
		Q.pop();
		bool check = false;
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X.X + dx[dir];
			int ny = cur.X.Y + dy[dir];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if(visited[nx][ny] || board[nx][ny] == -1)
				continue;
			check = true;
			Q.push({{nx,ny},cur.Y + 1});
			board[nx][ny] = 1;
			visited[nx][ny] = 1;
		}
		if(!check){
			if(cur.Y > mx)
				mx = cur.Y;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!board[i][j]){
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	cout << mx << '\n';
}

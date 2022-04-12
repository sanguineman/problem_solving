#include <bits/stdc++.h>  
using namespace std; 	
using ll = long long;  
const int INF = 5e5;  
#define X first
#define Y second
char board[1001][1001];
int w, h, T;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool visited[1001][1001];
queue <pair<pair<int,int>,int>> Q;
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> T;
	while(T--){
		cin >> w >> h;
		for(int i = 0; i < h; i++){
			string st;
			cin >> st;
			for(int j = 0; j < w; j++){
				board[i][j] = st[j];
			}
		}
		pair <int,int> start;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(board[i][j] == '*'){
					Q.push({{i,j},-1});
					visited[i][j] = 1;
				}
				else if(board[i][j] == '@'){
					start.X = i;
					start.Y = j;
					visited[i][j] = 1;
				}
			}
		}
		int mn = INT_MAX;
		Q.push({{start.X,start.Y},1});
		while(!Q.empty()){
			auto cur = Q.front();
			Q.pop();
			if(board[cur.X.X][cur.X.Y] == '@' && (cur.X.X == 0 || cur.X.X == h - 1 || cur.X.Y == 0 || cur.X.Y == w - 1)){
				if(cur.Y < mn)
					mn = cur.Y;
				continue;
			}
			for(int dir = 0; dir < 4; dir++){
				int nx = cur.X.X + dx[dir];
				int ny = cur.X.Y + dy[dir];
				if(nx < 0 || nx >= h || ny < 0 || ny >= w)
					continue;
				if(visited[nx][ny] || board[nx][ny] == '#')
					continue;
				if(board[cur.X.X][cur.X.Y] == '@'){
					if(board[nx][ny] == '*')
						continue;
					Q.push({{nx,ny},cur.Y+1});
					board[nx][ny] = '@';
					visited[nx][ny] = 1;
				}
				else if(board[cur.X.X][cur.X.Y] == '*'){
					Q.push({{nx,ny},-1});
					board[nx][ny] = '*';
					visited[nx][ny] = 1;
				}
			}
		}
		if(mn == INT_MAX)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << mn << '\n';
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				visited[i][j] = 0;
			}
		}
	}
}

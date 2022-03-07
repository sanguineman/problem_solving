#include <bits/stdc++.h>  
using namespace std; 	
using ll = long long;  
const int INF = 5e5;
#define X first
#define Y second  
int R, C, mn = INT_MAX;
char board[1001][1001];
bool visited[1001][1001];
queue <pair<pair<int,int>,int>> Q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> R >> C;
	pair <int,int> start;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> board[i][j];
			if(board[i][j] == 'F'){
				Q.push({{i,j},-1});
				visited[i][j] = 1;
			}
			else if(board[i][j] == 'J'){
				start.X = i;
				start.Y = j;
			}
		}
	}
	Q.push({{start.X,start.Y},0});
	visited[start.X][start.Y] = 1;
	while(!Q.empty()){
		pair<pair <int,int>,int> cur = Q.front();
		Q.pop();
		if(board[cur.X.X][cur.X.Y] != 'F' && (cur.X.X == 0 || cur.X.X == R - 1 || cur.X.Y == 0 || cur.X.Y == C - 1)){
			if(cur.Y + 1 < mn)
				mn = cur.Y + 1;
			continue;
		}
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X.X + dx[dir];
			int ny = cur.X.Y + dy[dir];
			if(nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if(visited[nx][ny] || board[nx][ny] == '#')
				continue;
			if(board[cur.X.X][cur.X.Y] == 'J'){
				if(board[nx][ny] == 'F')
					continue;
				board[nx][ny] = 'J';
				Q.push({{nx,ny},cur.Y + 1});
			}	
			else if(board[cur.X.X][cur.X.Y] == 'F'){
				board[nx][ny] = 'F';
				Q.push({{nx,ny},-1});		
			}
			visited[nx][ny] = 1;
		}
	}
	if(mn == INT_MAX)
		cout << "IMPOSSIBLE" << '\n';
	else
		cout << mn << '\n';
}

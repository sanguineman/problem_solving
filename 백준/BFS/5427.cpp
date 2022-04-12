#include <bits/stdc++.h> 
using namespace std; 
using ll = long long;  
const int LMT = 1e3;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int T, w, h;
char board[LMT+1][LMT+1];
int dist[LMT+1][LMT+1];
queue <pair<int,int>> Q;
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--){
		cin >> w >> h;
		for(int i = 0; i < h; i++)
			fill(dist[i],dist[i]+w,-1);
		pair <int,int> s;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> board[i][j];
				if(board[i][j] == '*'){
					Q.push({i,j});
				}
				else if(board[i][j] == '@'){
					s.X = i; 
					s.Y = j;
				}
			}
		}
		Q.push({s.X,s.Y});
		dist[s.X][s.Y] = 0;
		bool check = false;
		while(!Q.empty()){
			auto cur = Q.front(); Q.pop();
			if(board[cur.X][cur.Y] == '@' && (cur.X == 0 || cur.X == h-1 || cur.Y == 0 || cur.Y == w-1)){
				cout << dist[cur.X][cur.Y] + 1 << '\n';
				check = true;
				break;
			} 
			for(int dir = 0; dir < 4; dir++){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx < 0 || nx >= h || ny < 0 || ny >= w)
					continue;
				if(dist[nx][ny] >= 0 || board[nx][ny] == '*' || board[nx][ny] == '#')
					continue;
				if(board[cur.X][cur.Y] == '*'){
					Q.push({nx,ny});
					board[nx][ny] = '*';
				}
				else if(board[cur.X][cur.Y] == '@'){
					board[nx][ny] = '@';
					dist[nx][ny] = dist[cur.X][cur.Y] + 1;
					Q.push({nx,ny});
				}
			}
		}
		if(!check)
			cout << "IMPOSSIBLE" << '\n';
		while(!Q.empty()){
			Q.pop();
		}
	}
}

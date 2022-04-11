#include <bits/stdc++.h>  
using namespace std; 	
using ll = long long;  
const int INF = 5e5;  
#define X first
#define Y second
int T, I;
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
bool visited[301][301];
queue <pair<pair<int,int>,int>> Q;
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> T;
	while(T--){
		cin >> I;
		pair <int,int> now, after;
		cin >> now.X >> now.Y;
		cin >> after.X >> after.Y;
		Q.push({{now.X,now.Y},0});
		visited[now.X][now.Y] = 1;
		int mn = INF;
		while(!Q.empty()){
			auto cur = Q.front();
			Q.pop();
			if(cur.X.X == after.X && cur.X.Y == after.Y){
				if(cur.Y < mn)
					mn = cur.Y;
			}
			for(int dir = 0; dir < 8; dir++){
				int nx = cur.X.X + dx[dir];
				int ny = cur.X.Y + dy[dir];
				if(nx < 0 || nx >= I || ny < 0 || ny >= I)
					continue;
				if(visited[nx][ny])
					continue;
				Q.push({{nx,ny},cur.Y + 1});
				visited[nx][ny] = 1;
			}
		}
		cout << mn << '\n';
		for(int i = 0; i < I; i++){
			for(int j = 0; j < I; j++){
				visited[i][j] = 0;
			}
		}
	}
}

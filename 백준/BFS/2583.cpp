#include <bits/stdc++.h>  
using namespace std; 
using ll = long long;  
const int INF = 5e5;  
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int M, N, K, board[101][101];
bool visited[101][101];
queue <pair<int,int>> Q;
vector <int> ans;
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> M >> N >> K;
	while(K--){
		pair <int,int> a, b;
		cin >> a.Y >> a.X >> b.Y >> b.X;
		for(int i = a.X; i < b.X; i++){
			for(int j = a.Y; j < b.Y; j++){
				board[i][j] = -1;
			}
		}
	}
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(!board[i][j] && !visited[i][j]){
				int cnt = 1;
				Q.push({i,j});
				visited[i][j] =  1;
				while(!Q.empty()){
					auto cur = Q.front();
					Q.pop();
					for(int dir = 0; dir < 4; dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if(nx < 0 || nx >= M || ny < 0 || ny >= N)
							continue;
						if(visited[nx][ny] || board[nx][ny] == -1)
							continue;
						Q.push({nx,ny});
						visited[nx][ny] = 1;
						cnt++;
					}
				}
				ans.push_back(cnt);
			}
		}
	}
	sort(ans.begin(),ans.end());
	cout << ans.size() << '\n';
	for(auto & i : ans){
		cout << i << ' ';
	}
}

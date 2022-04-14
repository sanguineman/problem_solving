#include <bits/stdc++.h>  
using namespace std; 
using ll = long long;  
const int INF = 5e5; 
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 
int N, board[26][26];
bool visited[26][26];
queue <pair<int,int>> Q;
vector <int> ans;
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> N;
	for(int i = 0; i < N; i++){
		string st;
		cin >> st;
		for(int j = 0; j < N; j++){
			board[i][j] = st[j] - '0';
		}
	}
	int apartment = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(!visited[i][j] && board[i][j]){
				int cnt = 1;
				apartment++;
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
						if(visited[nx][ny] || !board[nx][ny])
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
	cout << apartment << '\n';
	for(auto & i : ans){
		cout << i << '\n';
	}
}

#include <bits/stdc++.h>  
using namespace std; 	
using ll = long long;  
const int INF = 5e5;  
#define X first
#define Y second
int T, I;
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
int dist[301][301]; // 굳이 bool visited[301][301]을 쓸 필요없이 dist 배열로 거리와 방문 체크를 동시에 진행 가능
queue <pair<int,int>> Q;
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> T;
	while(T--){
		cin >> I;
		pair <int,int> now, after;
		cin >> now.X >> now.Y;
		cin >> after.X >> after.Y;
		for(int i = 0; i < I; i++)
			fill(dist[i],dist[i]+I,-1);
		Q.push({now.X,now.Y});
		dist[now.X][now.Y] = 0;
		while(!Q.empty()){
			auto cur = Q.front();
			Q.pop();
			for(int dir = 0; dir < 8; dir++){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx < 0 || nx >= I || ny < 0 || ny >= I)
					continue;
				if(dist[nx][ny] >= 0)
					continue;
				Q.push({nx,ny});
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			}
		}
		cout << dist[after.X][after.Y] << '\n';
	}
}

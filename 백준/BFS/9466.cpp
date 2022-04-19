#include <bits/stdc++.h>  
using namespace std; 
using ll = long long;  
const int INF = 5e5;  
int T, n, student[100001];
bool visited[100001];
int dfs(int i){
	int cur = i;
	int cnt = 0, cycle = 0;
	while(!visited[cur]){
		visited[cur] = 1;
		cur = student[cur];
		cycle++;
	}
	while(i != cur){
		i = student[i];
		cnt++;
	}
	return (cycle - cnt);
}
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> T;
	while(T--){
		int ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> student[i];
		}
		for(int i = 1; i <= n; i++){
			if(!visited[i])
				ans += dfs(i);
		}
		cout << n - ans << '\n';
		fill(visited,visited+n+1,0);
	}
}

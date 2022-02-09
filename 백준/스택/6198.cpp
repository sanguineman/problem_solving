#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int N;
	ll ans = 0;
	int height[80005];
	stack <pair<int,int>> building;
	building.push({1000000001,0});
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> height[i];
	}
	for(int i = N; i >= 1; i--){
		if(building.top().first < height[i]){
			while(building.top().first < height[i]){
				building.pop();
			}
		}
		if(building.top().second == 0)
			ans += (N - i);
		else
			ans += (building.top().second - i - 1);
		building.push({height[i],i});
	}
	cout << ans << '\n';
}

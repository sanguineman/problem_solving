#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int arr[7][2];
int main(){
	int N, K, ans = 0;
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		int x, y;
		cin >> x >> y;
		arr[y][x]++;
	}
	for(int i = 1; i <= 6; i++){
		for(int j = 0; j < 2; j++){
			if(!arr[i][j])
				continue;
			if(arr[i][j] > K){
				ans += ((arr[i][j] - 1) / K + 1);
			}
			else{
				ans += 1;
			}
		}
	}
	cout << ans << '\n';
}

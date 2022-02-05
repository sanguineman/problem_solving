#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;
int arr[2000001];
int main(){
	int n, x, ans = 0;
	vector <int> v;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		v.push_back(a);
		arr[a]++;
	}
	cin >> x;
	for(int i = 0; i < n; i++){
		if(x > v[i] && x-v[i] != v[i] && arr[x-v[i]]){
			ans++;
			arr[v[i]] = 0;
		}
	}
	cout << ans << '\n';
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;
int arr[201];
int main(){
	int N, v;
	cin >> N;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		arr[a+100]++;
	}
	cin >> v;
	cout << arr[v+100] << '\n';
}

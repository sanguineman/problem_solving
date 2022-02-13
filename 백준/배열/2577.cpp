#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int num[10];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a, b, c, ans;
	cin >> a >> b >> c;
	ans = a * b * c;
	while(ans){
		num[ans%10]++;
		ans /= 10;
	}
	for(int i = 0; i < 10; i++){
		cout << num[i] << '\n';
	}
}

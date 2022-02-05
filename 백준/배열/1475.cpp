#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	int num[10] = {0,};
	int N, M = 0, mx = 0;
	cin >> N;
	while(N){
		num[N%10]++;
		N /= 10;
	}
	for(int i = 0; i < 10; i++){
		if(i == 6 || i == 9){
			M += num[i];
			continue;
		}
		if(num[i] > mx){
			mx = num[i];
		}
	}
	M = (M % 2 == 1) ? M / 2 + 1 : M / 2;
	cout << max(M,mx);
}

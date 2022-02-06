#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	int N, K;
	list <int> L;
	vector <int> ans;
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		L.push_back(i);
	}
	auto iter = L.begin();
	while(!L.empty()){
		for(int i = 0; i < K - 1; i++){
			if(iter == L.end()){
				iter = L.begin();
			}
			iter++;
		}
		if(iter == L.end()){
			iter = L.begin();
		}
		ans.push_back(*iter);
		iter = L.erase(iter);
	}
	cout << '<';
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
		if(i != ans.size() - 1)
			cout << ", ";
	}
	cout << '>';
}

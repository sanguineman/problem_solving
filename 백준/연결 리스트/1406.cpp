#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	list <char> L;
	string st;
	int M;
	cin >> st;
	for(auto i : st)
		L.push_back(i);
	auto iter = L.end();
	cin >> M;
	while(M--){
		char c;
		cin >> c;
		if(c == 'P'){
			char n;
			cin >> n;
			L.insert(iter,n);
		}
		else if(c == 'B'){
			if(iter == L.begin())
				continue;
			else{
				iter--;
				iter = L.erase(iter);
			}
		}
		else if(c == 'D'){
			if(iter == L.end())
				continue;
			iter++;
		}
		else{
			if(iter == L.begin())
				continue;
			iter--;
		}
	}
	
	for(auto i : L)
		cout << i;
}

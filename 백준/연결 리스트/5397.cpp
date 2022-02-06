#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	int T;
	cin >> T;
	while(T--){
		list <char> L;
		auto iter = L.end();
		string st;
		cin >> st;
		for(auto c : st){
			if(c == '<'){
				if(iter != L.begin())
					iter--;
			}
			else if(c == '>'){
				if(iter != L.end())
					iter++;
			}
			else if(c == '-'){
				if(iter != L.begin()){
					iter--;
					iter = L.erase(iter);
				}
			}
			else{
				L.insert(iter,c);
			}
		}
		for(auto i : L)
			cout << i;
		cout << '\n';
	}
}

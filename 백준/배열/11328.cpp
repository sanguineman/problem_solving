#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int arr[26];
int main(){
	int T;
	cin >> T;
	while(T--){
		string s1, s2;
		cin >> s1 >> s2;
		for(int i = 0; i < s1.size(); i++){
			arr[s1[i]-'a']++;
		}
		for(int i = 0; i < s2.size(); i++){
			arr[s2[i]-'a']--;
		}
		for(int i = 0; i < 26; i++){
			if(arr[i]){
				cout << "Impossible" << '\n';
				break;
			}
			else if(i == 25){
				cout << "Possible" << '\n';
			}
		}
		fill(arr,arr+26,0);
	}
}

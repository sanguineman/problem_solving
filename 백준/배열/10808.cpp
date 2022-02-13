#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	string s;
	int arr[26] = {0,};
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		arr[s[i]-'a']++;
	}
	for(int i = 0; i < 26; i++){
		cout << arr[i] << ' ';
	}
}

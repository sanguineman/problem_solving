#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int arr[26];
int main(){
	string s1, s2;
	int ans = 0;
	cin >> s1 >> s2;
	for(int i = 0; i < s1.size(); i++)
		arr[s1[i]-'a']++;
	for(int i = 0; i < s2.size(); i++)
		arr[s2[i]-'a']--;
	for(int i = 0; i < 26; i++){
		if(arr[i])
			ans += (arr[i] > 0) ? arr[i] : -arr[i];
	}
	cout << ans << '\n';
}

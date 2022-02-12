#include <bits/stdc++.h>  
using namespace std; 	
using ll = long long;  
const int INF = 5e5;  
int main() { 	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	int N;
	long long ans = 0;
	cin >> N;
	stack <pair<int,int>> height;
	for(int i = 0; i < N; i++){
		int h;
		cin >> h;
		if(height.empty()){
			height.push({h,0});
		}
		else{
			if(height.top().first > h){
				ans++;
				height.push({h,1});
			}
			else{
				while(!height.empty() && height.top().first < h){
				ans++;
				height.pop();
			}
			if(!height.empty() && height.top().first == h){
				ans = ans + height.top().second + 1;
			
				height.push({h,height.top().second + 1});	
			}
			else if(!height.empty() && height.top().first > h){
				ans++;
				height.push({h,1});
			}
			else{
				height.push({h,0});
			}
			}	
			
		}
	}
	cout << ans << '\n';
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;


int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T, n;
	deque <int> deq;
	string p, x;
	cin >> T;
	while(T--){
		int dir = 0, err = 0;
		cin >> p;
		cin >> n;
		cin >> x;
		for(int i = 0; i < x.size(); i++){
			int num = 0, place = 0;
			if(x[i] == ',' || x[i] == ']'){
				for(int j = i - 1; x[j] >= '0' && x[j] <= '9'; j--){
					num += (x[j] - '0') * pow(10,place);
					place++;
				}
			}
			if(num)
				deq.push_back(num);
		}
		for(int i = 0; i < p.size(); i++){
			if(p[i] == 'R')
				dir++;
			else{
				if(!deq.empty()){
					if(dir % 2){
						deq.pop_back();
					}
					else{
						deq.pop_front();
					}
				}
				else{
					err = 1;
					break;
				}
			}
		}
		if(err){
			cout << "error";
		}
		else{
			cout << '[';
			int s = deq.size();
			for(int i = 0; i < s;i++){
				if(dir % 2){
					if(i == s - 1)
						cout << deq.back();
					else
						cout << deq.back() << ',';
					deq.pop_back();	
				}	
				else{
					if(i == s - 1)
						cout << deq.front();
					else
						cout << deq.front() << ',';
					deq.pop_front();
				}
			}
			cout << ']';
		}
		cout << '\n';
		while(!deq.empty()){
			deq.pop_back();
		}
	}
}

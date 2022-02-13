#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int que[2000005];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int N, head = 0, tail = 0;
	cin >> N;
	while(N--){
		string st;
		cin >> st;
		if(st == "push"){
			int num;
			cin >> num;
			que[tail++] = num;
		}
		else if(st == "pop"){
			cout << (head == tail ? -1 : que[head++]) << '\n'; // cout << (head == tail) ? -1 : que[head] << '\n'; 로 하면 head == tail 의 값이 출력된다. 
      // 그 이유는 << 연산자의 우선순위가 가장 높기 때문이다. => 삼항연산자가 제 기능을 하지 못함.
		}
		else if(st == "size"){
			cout << tail - head << '\n';
		}
		else if(st == "empty"){
			cout << (head == tail ? 1 : 0) << '\n';
		}
		else if(st == "front"){
			cout << (head == tail ? -1 : que[head]) << '\n';
		}
		else if(st == "back"){
			cout << (head == tail ? -1 : que[tail-1]) << '\n';
		}
	}
}

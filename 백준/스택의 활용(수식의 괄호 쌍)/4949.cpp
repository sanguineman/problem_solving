#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(1){
		string st;
		bool isBalanced = true;
		getline(cin,st);
		if(st[0] == '.'){
			break;
		}
		stack <char> sk;
		for(auto & s : st){
			if(s == '.')
				break;
			if(s == '(' || s == '['){
				sk.push(s);
			}
			else if(s == ')'){
				if(sk.empty() || sk.top() != '('){
					isBalanced = false;
					break;
				}
				else
					sk.pop();
			}
			else if(s == ']'){
				if(sk.empty() || sk.top() != '['){
					isBalanced = false;
					break;
				}
				else
					sk.pop();
			}
		}
		if(!sk.empty())
			isBalanced = false;
		if(isBalanced)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
		cin.ignore();
	}
}

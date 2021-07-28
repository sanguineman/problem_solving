#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int T, N;
vector <int> v;
map <vector<int>,int> ways;

void bfs(){
  queue <vector<int>> que;
  vector <int> sorted(8);
  for(int i = 0; i < 8; i++)  sorted[i] = i + 1;
  que.push(sorted);
  ways[sorted] = 0;
  while(!que.empty()){
    auto here = que.front();
    que.pop();

    int dist = ways[here];
    for(int i = 0; i < 7; i++){
      for(int j = i + 2; j <= 8 ; j++){
        reverse(here.begin()+i,here.begin()+j);
        if(ways.count(here) == 0){
          ways[here] = dist + 1;
          que.push(here);
        }
        reverse(here.begin()+i,here.begin()+j);
      }
    }
  }
}

void solve(vector<int> seq){
  vector <int> newSeq(8);
  for(int i = 0; i < seq.size(); i++){
    int num = 1;
    for(int j = 0 ; j < seq.size(); j++){
      if(seq[i] > seq[j])
        num++;
    }
    newSeq[i] = num;
  }
  for(int i = seq.size() ; i < 8; i++)  newSeq[i] = i + 1;
  cout << ways[newSeq] << '\n';

}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> T;
  bfs();
  while(T--){
    cin >> N;
    for(int i = 0; i < N; i++){
      int a;
      cin >> a;
      v.push_back(a);
    }
    solve(v);
    v.clear();
  }
	return 0;
}

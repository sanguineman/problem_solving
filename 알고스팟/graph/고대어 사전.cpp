#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int T, N;
int graph[26][26];
bool visited[26];
vector <int> order;
void dfs(int here){
  visited[here] = true;
  for(int i = 0; i < 26; i++){
    if(graph[here][i] && !visited[i])
      dfs(i);
  }
  order.push_back(here);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    vector <string> st;
    for(int i = 0; i < N; i++){
      string s;
      cin >> s;
      st.push_back(s);
    }
    bool validity = true;
    for(int i = 0; i < N - 1 ; i++){
      int j = i + 1;
      int len = min(st[i].size(),st[j].size());
      for(int k = 0; k < len; k++){
        if(st[i][k] != st[j][k]){
          int xInt = st[i][k] - 'a', yInt = st[j][k] - 'a';
          graph[xInt][yInt] = 1;
          break;
        }
      }
    }
    for(int i = 0; i < 26; i++){
        if(!visited[i])
          dfs(i);
    }
    reverse(order.begin(),order.end());
    for(int i = 0; i < 26 ; i++){
      for(int j = i + 1; j < 26; j++){
        if(graph[order[j]][order[i]]){
          validity = false;
          break;
        }
      }
      if(!validity)
        break;
    }
    if(validity){
      for(int i = 0; i < order.size(); i++){
        cout << char(order[i]+97);
      }
    }
    else{
      cout << "INVALID HYPOTHESIS";
    }
    cout << '\n';
    for(int i = 0; i < 26; i++){
      visited[i] = false;
      for(int j = 0; j < 26; j++){
        graph[i][j] = 0;
      }
    }
    order.clear();
  }
	return 0;
}

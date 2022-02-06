#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 5e5;

int T, H, W, ans;
int board[20][20];
int coverBlock[4][3][2] = {
  {{0,0},{0,1},{1,1}},
  {{0,0},{1,0},{1,-1}},
  {{0,0},{1,0},{1,1}},
  {{0,0},{0,1},{1,0}}
};

bool check(int board[20][20], int y, int x, int typeBlock){
  for(int i = 0; i < 3; i++){
    int dY = y + coverBlock[typeBlock][i][0], dX = x + coverBlock[typeBlock][i][1];
    if(dY >= 0 && dY < H && dX >= 0 && dX < W){
      if(board[dY][dX] == 1){
        return false;
      }
    }
    else{
      return false;
    }
  }
  return true;
}

void solve(int board[20][20]){
  bool isBoardFull = true;
  pair <int,int> p = {-1,-1};
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(p.first == -1 && p.second == -1 && board[i][j] == 0){
        p.first = i;
        p.second = j;
        isBoardFull = false;
        break;
      }
    }
    if(!isBoardFull)
      break;
  }
  if(isBoardFull){
    ans++;
    return;
  }
  for(int k = 0; k < 4; k++){
    if(check(board,p.first,p.second,k)){
      for(int i = 0; i < 3; i++){
        int y = p.first + coverBlock[k][i][0], x = p.second + coverBlock[k][i][1];
        board[y][x] = 1;
      }
      solve(board);
      for(int i = 0; i < 3; i++){
        int y = p.first + coverBlock[k][i][0], x = p.second + coverBlock[k][i][1];
        board[y][x] = 0;
      }
    }
  }
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> T;
  while(T--){
    cin >> H >> W;
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        char c;
        cin >> c;
        board[i][j] = (c == '#') ? 1 : 0;
      }
    }
    solve(board);
    cout << ans << '\n';
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        board[i][j] = 0;
      }
    }
    ans = 0;
  }
  

	return 0;
}

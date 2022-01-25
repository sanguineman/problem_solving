#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack <int> basket;  
    for(int i = 0; i < moves.size(); i++){
        int j = 0;
        while(j < board.size()){
            if(!board[j][moves[i]-1]){
                j++;
            }
            else{
                if(basket.empty() || basket.top() != board[j][moves[i]-1]){
                    basket.push(board[j][moves[i]-1]);
                }
                else{
                    answer += 2;
                    basket.pop();
                }
                board[j][moves[i]-1] = 0;
                break;
            }
        }
    }
    return answer;
}

#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair <int,int> pos_l = {3,0}, pos_r = {3,2}; 
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += 'L';
            pos_l.first = (numbers[i] - 1) / 3;
            pos_l.second = (numbers[i] - 1) % 3;
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += 'R';
            pos_r.first = (numbers[i] - 1) / 3;
            pos_r.second = (numbers[i] - 1) % 3;
        }
        else{ // 2, 5, 8, 0
            int dist_l, dist_r;
            pair <int,int> cur_pos;
            if(numbers[i] == 0)
                cur_pos = {3,1};
            else
                cur_pos = {(numbers[i] - 1) / 3, (numbers[i] - 1) % 3};
            dist_l = abs(cur_pos.first - pos_l.first) + abs(cur_pos.second - pos_l.second);
            dist_r = abs(cur_pos.first - pos_r.first) + abs(cur_pos.second - pos_r.second);
            if(dist_l == dist_r){
                if(hand == "right"){
                    answer += 'R';
                    pos_r.first = cur_pos.first;
                    pos_r.second = cur_pos.second;
                }
                else{
                    answer += 'L';
                    pos_l.first = cur_pos.first;
                    pos_l.second = cur_pos.second;
                }
            }
            else{
                if(dist_l < dist_r){
                    answer += 'L';
                    pos_l.first = cur_pos.first;
                    pos_l.second = cur_pos.second;
                }
                else{
                    answer += 'R';
                    pos_r.first = cur_pos.first;
                    pos_r.second = cur_pos.second;
                }
            }
        }
    }
    return answer;
}

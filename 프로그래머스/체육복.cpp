#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    bool gave[31] = {false};
    bool given[31] = {false};
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    for(int i : reserve){
        for(int j : lost){
            if( i == j ){
                gave[i] = true;
                given[j] = true;
            }
        }
    }
    for(int i : reserve){
        for(int j : lost){
            if((i - j == 1 || i - j == -1) && !gave[i] && !given[j] ){
                gave[i] = true;
                given[j] = true;
            } 
        }
    }
    answer += (n - lost.size());
    for(int i : lost){
        if(given[i] == true)
            answer++;
    }
    return answer;
}

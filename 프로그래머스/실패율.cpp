#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,double>&a,const pair<int,double>&b){
    if(a.second == b.second){
        if(a.first < b.first){
            return true;
        }
        return false;
    }
    else if(a.second < b.second){
        return false;
    }
    else{
        return true;
    }
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    pair <int,double> fail[505];
    for(int i = 1; i <= N; i++){
        fail[i].second = 0;
    }

    for(int i = 1; i <= N; i++){
        double players = 0, yet = 0;
        for(int j : stages){
            if(j >= i){
                players += 1;
            }
            if(j == i){
                yet += 1;
            }
        }
        fail[i].first = i;
        if(players == 0)
            fail[i].second = 0;

        else
            fail[i].second = yet/players;
    }
    sort(fail+1,fail+N+1,cmp);
    for(int i = 1; i <= N; i++){
        answer.push_back(fail[i].first);
    }
    return answer;
}

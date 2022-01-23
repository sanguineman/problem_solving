#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int num1 = 0, num2 = 0, num3 = 0;
    vector <int> n1 = {1,2,3,4,5};
    vector <int> n2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector <int> n3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector <pair<int,int>> ans; 
    for(int i = 0 ; i < answers.size(); i++){
        if(answers[i] == n1[i%5]){
            num1++;
        }
        if(answers[i] == n2[i%8]){
            num2++;
        }
        if(answers[i] == n3[i%10]){
            num3++;
        }
    }
    ans.push_back({num1,1});
    ans.push_back({num2,2});
    ans.push_back({num3,3});
    sort(ans.begin(),ans.end(),greater<>());
    int mx = 0, cnt = 0;
    for(int i = 0; i < 3; i++){
        if(ans[i].first >= mx){
            mx = ans[i].first;
            cnt++;
        }
    }
    for(int i = 0; i < cnt; i++){
        answer.push_back(ans[i].second);
    }
    sort(answer.begin(),answer.end());
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map <string,int> mp;
    set <string> rep;
    map <string, int> num;
    map <string, vector<string>> who;
    for(auto & i : id_list){
        mp.insert({i,0});
    }
    for(int i = 0 ; i < report.size(); i++){
        rep.insert(report[i]);
    }
    for(auto iter = rep.begin(); iter != rep.end(); iter++){
        string s = *iter;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                string s1, s2;
                s1 = s.substr(0,i);
                s2 = s.substr(i+1);
                if(num.find(s2) != num.end()){
                    num[s2] += 1;
                }
                else
                    num.insert({s2,1});
                who[s2].push_back(s1);
            }
        }
    }

    for(auto iter = num.begin(); iter != num.end(); iter++){
        if(iter->second >= k){
            for(int i = 0; i < who[iter->first].size(); i++){
                mp[who[iter->first][i]] += 1;
            }
        }
    }

    for(int i = 0; i < id_list.size(); i++){
        answer.push_back(mp[id_list[i]]);
    }

    return answer;
}

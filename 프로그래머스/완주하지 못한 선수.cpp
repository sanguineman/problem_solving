#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map <string,int> mp;
    for(string s : participant){
        if(mp.find(s) == mp.end()){
            mp.insert({s,1});
        }
        else{
            mp[s] += 1;
        }
    }
    for(string s : completion){
        mp[s]--;
    }
    
    for(auto iter : mp){
        if(iter.second == 1){
            answer += iter.first;
        }
    }
    return answer;
}

#include <string>
#include <vector>
#include <map>
#include <regex>

using namespace std;

int solution(string s) {
    int answer = 0;
    string st = "";
    map <string,int> mp;
    vector <string> num = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    for(int i = 0; i <= 9; i++){
        mp[num[i]] = i;
    }
    smatch match;
    regex re("zero|one|two|three|four|five|six|seven|eight|nine");
    while(regex_search(s,match,re)){
        for(auto & i : match){
            s =  regex_replace(s, regex(i.str()),to_string(mp[i.str()]));
        }
    }
    answer = stoi(s);
    return answer;
}

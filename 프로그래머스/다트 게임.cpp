#include <string>
#include <vector>
#include <regex>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector <string> dart;
    vector <int> num;
    vector <char> bonus;
    vector <char> option;
    regex re("[0-9]{0,2}[SDT]{1}[*#]?");
    smatch match;
    while(regex_search(dartResult,match,re)){
        dart.push_back(match.str());
        dartResult = match.suffix();
    }
    for(int i = 0; i < dart.size(); i++){
        for(int j = 0; j < dart[i].size(); j++){
            if(dart[i][j] == 'S' || dart[i][j] == 'D' || dart[i][j] == 'T'){
                num.push_back(stoi(dart[i].substr(0,j)));
                bonus.push_back(dart[i][j]);
                if(j != dart[i].size() - 1 )
                    option.push_back(dart[i][j+1]);
                else
                    option.push_back('0');
            }
        }
    }
    for(int i = 0; i < bonus.size(); i++){
        if(bonus[i] == 'D'){
            num[i] = pow(num[i],2);
        }
        else if(bonus[i] == 'T'){
            num[i] = pow(num[i],3);
        }
    }

    for(int i = 0; i < option.size(); i++){
        if(option[i] == '0')
            continue;
        if(option[i] == '*'){
            if(i == 0){
                num[i] = num[i] * 2;
            }
            else{
                for(int j = i - 1; j <= i ; j++){
                    num[j] = num[j] * 2;
                }
            }
        }
        else{
            num[i] = -num[i];
        }
    }
    for(int i = 0; i < num.size(); i++){
        answer += num[i];
    }
    return answer;
}

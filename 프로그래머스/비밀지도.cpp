#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

string decoding(int n, int password){
    string st = "";
    string s = "";
    while(password){
       st += password % 2 + '0';
       password /= 2;
    }
    for(int i = 0; i < n - st.size(); i++){
        s += '0';
    }
    reverse(st.begin(),st.end());
    s += st;
    return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++){
        string s1, s2, ans = "";
        s1 = decoding(n, arr1[i]);
        s2 = decoding(n, arr2[i]);
        for(int i = 0; i < n; i++){
            if((s1[i] - '0') || (s2[i] - '0')){
                ans += '#';
            }
            else{
                ans += ' ';
            }
        }
        
        answer.push_back(ans);
    }
    return answer;
}

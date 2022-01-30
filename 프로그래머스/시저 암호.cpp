#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ')
            continue;
        else if(islower(s[i]) && s[i] + n > 'z'){ 
            s[i] = s[i] + n - 'z' + 'a' - 1;
        }
        else if(isupper(s[i]) && s[i] + n > 'Z'){
            s[i] = s[i] + n - 'Z' + 'A' - 1;
        }
      /* 'z' 나 'Z' 가 넘어가면, 다시 'a'나 'A' 가 된다. 모범 답안은 알파벳이 26개라는 것을 이용하여 나머지 연산을 하는 것 같다. 알아두자. 
      'a' + (s[i] - 'a' + n) % 26 'A' + (s[i] - 'A' + n) % 26 */
        else
            s[i] = s[i] + n;
    }
    answer = s;
    return answer;
}

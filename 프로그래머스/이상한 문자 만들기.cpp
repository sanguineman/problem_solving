#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int npos = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            for(int j = 0; j < i-npos; j++){
                if(j % 2 == 0)
                    s[j+npos] = toupper(s[j+npos]);
                else
                    s[j+npos] = tolower(s[j+npos]);
            }
            npos = i + 1;
        }
        else if(i == s.length()-1 && s[i] != ' '){
            for(int j = 0; j <= i-npos; j++){
                if(j % 2 == 0)
                    s[j+npos] = toupper(s[j+npos]);
                else
                    s[j+npos] = tolower(s[j+npos]);
            }
        }
    }
    answer = s;
    return answer;
}
/* 항상 드는 생각이지만, 문제를 잘 읽어야 정확하고 문제의 의도에 맞게 풀 수 있는 것 같다. 이 문제같은 경우에는 본래 문자열의 다른 부분은 훼손하지 않고, 문자열 내 단어들의 짝수 인덱스는
대문자로, 홀수 인덱스는 소문자로 변환하는 것이 핵심이었다. 단어와 단어 사이에 "하나 이상의 공백문자"가 들어갈 수 있다고 문제에 명시되어 있는데, 이를 무시하고 공백을 기준으로 단어를 파싱한다거나 
하는 작업을 해서는 안 된다. 처음 풀 때는 그러지 않았지만, 문제를 다 풀고나서 다른 방법은 없을까 고민하던 중, 공백을 기준으로 단어를 파싱하여 작업하는 방법을 떠올렸는데, 이 방법은 일단 테스트 
케이스 조차도 통과되지 않았을 뿐더러, 틀린 이유를 찾다보니 내 접근은 엄연히 문제의 의도와는 맞지 않는 잘못된 접근이었다. 여태까지 문제를 풀면서 느끼는건데, 문제를 정확하게 
분석하는 데에 투자하는 시간이 후에 문제를 잘못 읽어서 오류를 찾는 시간보다 짧을 확률이 더 크다. 문제를 잘 읽자. */

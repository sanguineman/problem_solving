#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int n = 0;
    string st = to_string(x); 
    for(int i = 0; i < st.length(); i++){
        n += st[i] - '0';
    }
    /* 나머지 연산으로 자릿수를 추출해내는 방법도 있다는 것을 알아두자. */
    answer = (x % n == 0) ? true : false;
    return answer;
}

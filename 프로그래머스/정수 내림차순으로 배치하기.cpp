#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector <int> x;
    string st;
    while(n > 0){
        x.push_back(n%10);
        n /= 10;
    }
    sort(x.begin(),x.end(),greater<>());
    /* 문자열 형태의 수, 예를 들어, string st = "152839" 를 sort(st.begin(),st.end(),greater<char>()); 하면 , st == 985321 이 된다. 문자열도 정렬이 된다! */
    for(auto & i : x){
        st += (char)(i+48);
    }
    answer = stol(st);
    return answer;
}

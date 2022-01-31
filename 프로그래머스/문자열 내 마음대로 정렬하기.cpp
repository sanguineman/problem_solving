#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int index;

bool cmp(const string & a, const string & b){
    if(a[index] < b[index])
        return true;
    else if(a[index] > b[index])
        return false;
    else{
        return a < b;
    }
  /* 삼항연산자를 이용해서 간단하게 코드를 줄일 수 있다. 삼항연산자에서 반환값이 꼭 단순한 값이 아닌, 논리 연산이 될 수도 있다는 점을 알아두자. */ 
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    index = n;
    sort(strings.begin(),strings.end(),cmp);
    answer = strings;
    return answer;
}

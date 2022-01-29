#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    double rt = sqrt(n); /* long long rt = sqrt(n) => 소수점 이하를 버린다 */ 
    if(rt - (long long)floor(rt) == 0){
        answer = (rt+1) * (rt+1);
    }
    return answer;
}

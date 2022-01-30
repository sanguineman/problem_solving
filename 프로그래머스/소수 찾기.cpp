#include <string>
#include <vector>
#include <cmath>

using namespace std;
bool prime[1000005];

int solution(int n) {
    int answer = 0;
    for(int i = 0 ; i <= 1000000; i++){
        prime[i] = true;
    }
    for(int i = 2; i <= sqrt(1000000); i++){
        if(!prime[i])
            continue;
        for(int j = i * i; j <= 1000000; j += i){
                prime[j] = false;
        }
    }
    /* 에라토스테네스의 체, 두 번째 for 문의 j 가 i * i 부터 시작하는 이유는 i * i 보다 작은 합성수 m = a * b 라고 가정했을 때, a와 b 중 적어도 하나의 수는 i * i 의 제곱근보다 작아서 이미
    앞에서 지워졌기 때문이다. 동일한 이유로 첫 번째 for 문에서 n 까지의 배수를 체크하는 것이 아니라, n의 제곱근의 정수 부분까지만 체크한다. */ 
    for(int i = 2; i <= n; i++){
        if(prime[i]){
            answer += 1;
        }
    }
    return answer;
}

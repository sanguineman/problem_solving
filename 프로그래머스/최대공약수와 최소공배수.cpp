#include <string>
#include <vector>

using namespace std;

int Euclidean(int a, int b){
    int r = a % b;
    if(r == 0){
        return b;
    }
    return Euclidean(b,r);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int gcd = Euclidean(n,m);
    int lcm = n * m / Euclidean(n,m);
    answer.push_back(gcd);
    answer.push_back(lcm);
    return answer;
}

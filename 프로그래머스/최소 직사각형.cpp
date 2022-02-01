#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_w = sizes[0][0], max_h = sizes[0][1];
    for(int i = 1; i < sizes.size(); i++){
        if(max(max_w,sizes[i][0])*max(max_h,sizes[i][1]) < max(max_w,sizes[i][1])*max(max_h,sizes[i][0])){
            max_w = max(max_w,sizes[i][0]);
            max_h = max(max_h,sizes[i][1]);
        }
        else{
            max_w = max(max_w,sizes[i][1]);
            max_h = max(max_h,sizes[i][0]);
        }
      /* 이 문제의 핵심은 직사각형의 가로와 세로가 딱히 상관없고, 저장되어 있는 가로 최댓값과 세로 최댓값 중에 더 큰 것을 새로운 직사각형의 가로와 세로 중 더 큰 것과 비교해 더 큰 것으로 최댓값을 
      갱신한다는 것이다. 조금만 더 생각했으면, 코드가 더 간결해질 수 있었을 것 같다. */
    }
    answer = max_w * max_h;
    return answer;
}

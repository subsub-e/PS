#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(int i = begin; i <= end; i++){
        if(i == 1){
            answer.push_back(0);
        }
        else{
            int temp = 1;
            for(int j = 2; j <= sqrt(i); j++){
                if(i % j == 0 && i / j <= 10000000){
                    temp = max(temp, i / j);
                }
                else if(i % j == 0 && i / j > 10000000){
                    temp = max(temp, j);
                }
            }
            answer.push_back(temp);
        }
    }
    return answer;
}
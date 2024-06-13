#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int sum1 = 0;
    int sum2 = 0;
    for(int i = n-1; i >= 0; i--){
        sum1 -= deliveries[i];
        sum2 -= pickups[i];
        int cnt = 0;
        while(sum1 < 0 || sum2 < 0){
            sum1 += cap;
            sum2 += cap;
            cnt++;
        }
        answer += ((i + 1) * 2 * cnt);
        //cout << i << ' ' << answer << '\n';
    }
    return answer;
}
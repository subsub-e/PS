#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    while(left <= right){
        int x = left / n;
        int y = left % n;
        left++;
        answer.push_back(max(x, y) + 1);
    }

    return answer;
}
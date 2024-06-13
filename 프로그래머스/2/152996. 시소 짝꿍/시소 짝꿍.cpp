#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

unordered_map<double, int> m;

long long solution(vector<int> weights) {
    long long answer = 0;
    for(int i = 0; i < weights.size(); i++){
        double temp = (double) weights[i];
        answer += m[temp] + m[temp * 2] + m[temp / 2] + m[temp * 2 / 3] + m[temp * 3 / 2] + m[temp * 4 / 3] + m[temp * 3 / 4];
        m[temp]++;
    }
    for(auto it : m){
        cout << it.first << ' ' << it.second << '\n';
    }
    return answer;
}
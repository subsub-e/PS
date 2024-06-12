#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> v;
    int cnt = 0;
    int temp = k;
    while(k != 1){
        if(k % 2 == 0){
            k /= 2;
            double t = double (temp + k) / 2;
            v.push_back(t);
            temp = k;
            cnt++;
        }
        else{
            k = k * 3 + 1;
            double t = double (temp + k) / 2;
            v.push_back(t);
            temp = k;
            cnt++;
        }
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    
    for(int i = 0; i < ranges.size(); i++){
        double sum = 0;
        if(ranges[i][0] > (cnt + ranges[i][1])){
            answer.push_back(-1);
            continue;
        }
        for(int j = ranges[i][0]; j < (cnt + ranges[i][1]); j++){
            sum += v[j];
        }
        answer.push_back(sum);
    }
    return answer;
}
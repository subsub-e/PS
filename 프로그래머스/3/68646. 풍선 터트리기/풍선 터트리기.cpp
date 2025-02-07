#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> v1;
vector<int> v2;

int solution(vector<int> a) {
    int answer = 0;
    int minans = 1e9 + 10;
    for(int i = 0; i < a.size() - 2; i++){
        minans = min(minans, a[i]);
        v1.push_back(minans);
    }
    
    minans = 1e9 + 10;
    for(int i = a.size() - 1; i > 1; i--){
        minans = min(minans, a[i]);
        v2.push_back(minans);
    }
    
    int cnt = 2;
    
    for(int i = 1; i < a.size() - 1; i++){
        //cout << v1[i-1] << ' ' << v2[v2.size() - i] << '\n';
        if(a[i] < v1[i - 1] || a[i] < v2[v2.size() - i]){
            cnt++;
        }
    }
    
    
    return cnt;
}
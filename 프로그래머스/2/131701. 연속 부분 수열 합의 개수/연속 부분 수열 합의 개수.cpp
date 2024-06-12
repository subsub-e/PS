#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

unordered_set<int> s;



void func(int x, vector<int> v){
    
    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i] << ' ';
    // }
    // cout << '\n';
    
    for(int i = 0; i < v.size() - x + 1; i++){
        int sum = 0;
        for(int j = i; j < x + i; j++){
            sum += v[j];
        }
        //cout << sum << '\n';
        s.insert(sum);
    }
    return;
}

int solution(vector<int> elements) {
    int answer = 0;
    vector<int> v;
    v = elements;
    for(int i = 1; i < elements.size() + 1; i++){
        if(i == 1){
            func(i, v);
            continue;
        }
        for(int j = i - 2; j < i-1; j++){
            v.push_back(elements[j]);
        }
        func(i, v);
    }
    answer = s.size();
    return answer;
}
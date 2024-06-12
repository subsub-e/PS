#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<pair<string, int> > m1;

vector<string> temp;

bool func(int index){
    map<string, int> m2;
    vector<pair<string, int> > v;
    for(int i = index; i < index + 10; i++){
        m2[temp[i]]++;
    }
    for(auto it : m2){
        v.push_back(make_pair(it.first, it.second));
    }
    sort(v.begin(), v.end());
    if(v == m1){
        return true;
    }
    else{
        return false;
    }
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    temp = discount;
    for(int i = 0; i < want.size(); i++){
        m1.push_back(make_pair(want[i], number[i]));
    }
    sort(m1.begin(), m1.end());
    
    for(int i = 0; i < discount.size() - 9; i++){
        if(find(want.begin(), want.end(), discount[i]) != want.end()){
            //cout << i << '\n';
            if(func(i)){
                answer++;
            }
        }
    }
    return answer;
}
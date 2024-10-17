#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<pair<int, int> > v;
    
    for(int i = 3; i <= brown / 4 + 1; i++){
        v.push_back(make_pair(i, (brown - i * 2) / 2 + 2));
    }
    
    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i].first << ' ' << v[i].second << '\n';
    // }
    
    for(int i = 0; i < v.size(); i++){
        int temp = (v[i].first - 2) * (v[i].second - 2);
        if(temp == yellow){
            answer.push_back(v[i].second);
            answer.push_back(v[i].first);
            break;
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool visited[13];
int answer = 0;
vector<pair<int, int> > v;

void func(int now, int n){
    if(now == n){
        answer++;
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            int flag = 0;
            for(int j = 0; j < v.size(); j++){
                int nx = v[j].first;
                int ny = v[j].second;
                if(abs(nx - now) == abs(ny - i)){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                visited[i] = 1;
                v.push_back(make_pair(now, i));
                func(now + 1, n);
                visited[i] = 0;
                v.pop_back();
            }
        }
    }
    return;
}

int solution(int n) {
    
    
    func(0, n);
    
    return answer;
}
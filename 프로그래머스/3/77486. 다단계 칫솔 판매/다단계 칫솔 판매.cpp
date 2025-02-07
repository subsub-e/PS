#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int parent[10001];
int sell[10001];
unordered_map<string, int> m;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    parent[0] = -1;
    
    int index = 1;
    for(int i = 0; i < enroll.size(); i++){
        m[enroll[i]] = index++;
    }
    
    for(int i = 0; i < referral.size(); i++){
        if(referral[i] == "-"){
            parent[i + 1] = 0;
        }
        else{
            parent[i + 1] = m[referral[i]];
        }
    }
    
    for(int i = 0; i < amount.size(); i++){
        int now = m[seller[i]];
        int am = amount[i] * 100;
        
        while(now != -1){
            int temp = am / 10;
            am -= temp;
            sell[now] += am;
            am = temp;
            now = parent[now];
        }
        
    }
    
    for(int i = 1; i < enroll.size() + 1; i++){
        answer.push_back(sell[i]);
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

vector<unordered_set<int> > dp(8);

int func(int n, int k){
    string str = "";
    
    for(int i = 0; i < k + 1; i++){
        str += to_string(n);
    }
    
    return stoi(str);
}

int solution(int N, int number) {
    int answer = 0;
    
    dp[0].insert(N);
    
    for(int k = 1; k < 8; k++){
        
        dp[k].insert(func(N, k));
        
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                if(i + j + 1 != k){
                    continue;
                }
                
                for(auto a : dp[i]){
                    for(auto b : dp[j]){
                        dp[k].insert(a + b);
                        
                        if(a - b > 0){
                            dp[k].insert(a - b);
                        }
                        
                        dp[k].insert(a * b);
                        
                        if(b != 0){
                            dp[k].insert(a / b);
                        }
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < 8; i++){
        for(auto now : dp[i]){
            if(number == now){
                return i + 1;
            }
        }
    }
    
    return -1;
}
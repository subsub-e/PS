#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int solution(vector<int> a) {
    vector<int> cnt((int) a.size() + 1, 0);
    
    int answer = -1;
    
    for(int i = 0; i < a.size(); i++){
        cnt[a[i]]++;
    }
    
    for(int i = 0; i < cnt.size(); i++){
        if(cnt[i]  == 0){
            continue;
        }
        if(cnt[i] <= answer){
            continue;
        }
        
        int result = 0;
        
        for(int j = 0; j < a.size() - 1; j++){
            if(a[j] == a[j + 1]){
                continue;
            }
            if(a[j] != i && a[j + 1] != i){
                continue;
            }
            result++;
            j++;
        }
        //cout << i << ' ' << result << '\n';
        answer = max(answer, result);
    }
    
    return answer * 2;
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    
    int lo = 0;
    int high= 1e8 + 10;
    int work;
    
    while(lo <= high){
        int mid = (lo + high) / 2;
        int cnt = cores.size();
        for(int i = 0; i < cores.size(); i++){
            cnt += mid / cores[i];
        }
        if(n <= cnt){
            high = mid - 1;
            work = cnt;
        }
        else{
            lo = mid + 1;
        }
    }
    
    // if(n - cores.size() <= 0){
    //     return n;
    // }
    
    for(int i = cores.size() - 1; i >= 0; i--){
        if(lo % cores[i] == 0){
            if(work == n){
                return i + 1;
            }
            work--;
        }
    }
    
    
    return 0;
}
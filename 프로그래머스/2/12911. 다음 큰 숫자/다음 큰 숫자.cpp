#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int temp = n;
    int cnt = 0;
    while(temp >= 1){
        if(temp % 2 == 1){
            cnt++;
        }
        temp /= 2;
    }
    //cout << cnt << '\n';
    n++;
    while(1){
        int temp1 = n;
        int cnt1 = 0;
        while(temp1 != 0){
            if(temp1 % 2 == 1){
                cnt1++;
            }
            temp1 /= 2;
        }
        if(cnt1 == cnt){
            break;
        }
        n++;
    }
    
    return n;
}
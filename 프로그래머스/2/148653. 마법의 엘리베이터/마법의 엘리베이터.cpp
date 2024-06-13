#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int answer;

void func(int x, int cnt){
    if(x < 10){
        answer = min(x, 10 - x + 1) + cnt;
        return;
    }
    
    int a = x % 10;
    int b = 10 - x % 10;
    //cout << a << ' ' << b << '\n';
    if(x / 10 > 0){
        if(a > b || (b == 5 && (x % 100) / 10 >= 5)){
            func((x + b) / 10, cnt + b);
        }
        else{
            func((x - a) / 10, cnt + a);
        }
    }
}

int solution(int storey) {
    func(storey, 0);
    return answer;
}
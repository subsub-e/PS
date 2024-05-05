#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while(1){
        if(a < b){
            if(a / 2 + 1 == b / 2 && b - a == 1){
                break;
            }
        }
        else{
            if(b / 2 + 1 == a / 2 && a - b == 1){
                break;
            }
        }
        if(a % 2 == 1){
            a = a / 2 + 1;
        }
        else{
            a /= 2;
        }
        if(b % 2 == 1){
            b = b / 2 + 1;
        }
        else{
            b /= 2;
        }
        answer++;
        
    }
    //cout << "Hello Cpp" << endl;

    return answer + 1;
}
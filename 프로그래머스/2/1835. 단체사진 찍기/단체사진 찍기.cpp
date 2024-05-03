#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check(char c, int x, int y){
    if(c == '='){
        return x == y;
    }
    else if(c == '>'){
        return x > y;
    }
    else{
        return x < y;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string str = "ACFJMNRT";
    sort(str.begin(), str.end());
    
    do {
        int flag = 0;
        for(string text : data){
            int firstIdx = str.find(text[0]);
            int secondIdx = str.find(text[2]);
            int diff = abs(secondIdx - firstIdx) - 1;
            int num = text[4] - '0';
            
            if(check(text[3], diff, num)){
                continue;
            }
            flag = 1;
            break;
        }
        if(flag == 0){
            answer++;
        }
        
    }while(next_permutation(str.begin(), str.end()));
    return answer;
}
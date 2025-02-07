#include <iostream>
#include <string>
using namespace std;

int pali(string s, int left, int right){
    while(left >= 0 && right < s.length()){
        if(s[left] != s[right]){
            break;
        }
        left--;
        right++;
    }
    return right - left - 1;
}

int solution(string s)
{
    int answer=1;

    for(int i = 1; i < s.length(); i++){
        int left = i - 1;
        int right = i + 1;
        int odd = pali(s, left, right);
        int even = pali(s, left, right - 1);
        answer = max(answer, max(odd, even));
    }

    return answer;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for(int i = 0; i < s.size(); i++){
        string str = s[i];
        int cnt1 = 0;
        int cnt2 = 0;
        string ans = "";
        for(int j = 0; j < str.length(); j++){
            if(str[j] == '1'){
                //cout << 1 << '\n';
                cnt1++;
            }
            else{
                if(cnt1 >= 2){
                    cnt1 -= 2;
                    cnt2++;
                }
                else{
                    while(cnt1){
                        ans += "1";
                        cnt1--;
                    }
                    ans += "0";
                }
            }
        }
        
        while(cnt2){
            ans += "110";
            cnt2--;
        }
        while(cnt1){
            ans += "1";
            cnt1--;
        }
        answer.push_back(ans);
    }
    
    return answer;
}
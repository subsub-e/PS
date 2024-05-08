#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    int index = 1;
    //cout << (char) ('A' + 1) << '\n';
    for(int i = 0; i < 26; i++){
        char c = 'A' + i;
        string s(1, c);
        m[s] = index++;
    }
    
    for(int i = 0; i < msg.length(); i++){
        for(int j = msg.length() - i; j > 0; j--){
            if(m.find(msg.substr(i, j)) != m.end()){
                answer.push_back(m[msg.substr(i, j)]);
                //cout << j << ' ' << msg.substr(i, j) << '\n';
                
                if(i + j < msg.length()){
                    m[msg.substr(i, j + 1)] = index++;
                }
                i += (j - 1);
                break;
            }
        }
    }
    return answer;
}
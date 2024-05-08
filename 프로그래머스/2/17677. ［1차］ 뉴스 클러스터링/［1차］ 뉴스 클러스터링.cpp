#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int solution(string str1, string str2) {
    //int answer = 0;
    vector<string> temp1, temp2;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    for(int i = 0; i < str1.length() - 1; i++){
        string temp = str1.substr(i, 2);
        if(temp[0] >= 'a' && temp[0] <= 'z' && temp[1] >= 'a' && temp[1] <= 'z'){
            temp1.push_back(temp);
        }
    }
    for(int i = 0; i < str2.length() - 1; i++){
        string temp = str2.substr(i, 2);
        if(temp[0] >= 'a' && temp[0] <= 'z' && temp[1] >= 'a' && temp[1] <= 'z'){
            temp2.push_back(temp);
        }
    }
    
    double sum = temp1.size() + temp2.size();
    double cnt = 0;
    if(temp1.empty() && temp2.empty()){
        return 65536;
    }
    //cout << temp1.size() << ' ' << temp2.size();
    
    if(temp1.size() > temp2.size()){
        for(int i = 0; i < temp2.size(); i++){
            auto itr = find(temp1.begin(), temp1.end(), temp2[i]);
            if(itr != temp1.end()){
                cnt++;
                temp1.erase(itr);
            }
        }
    }
    else{
        for(int i = 0; i < temp1.size(); i++){
            auto itr = find(temp2.begin(), temp2.end(), temp1[i]);
            if(itr != temp2.end()){
                cnt++;
                temp2.erase(itr);
                //cout << *itr << '\n';
            }
        }
    }
    
    sum -= cnt;
    if(sum == 0){
        return 65536;
    }
    
    double answer = (double) cnt / (double) sum;
    
    return answer * 65536;
}
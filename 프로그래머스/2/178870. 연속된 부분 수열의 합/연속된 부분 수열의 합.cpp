#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int minans = 1e9 + 10;
    int st = 0;
    int en = 0;
    int sum = 0;
    vector<int> v;
    while(en < (int) sequence.size()){
        sum += sequence[en];
        while(sum > k){
            sum -= sequence[st++];
        }
        if(sum == k){
            if(minans > (en - st)){
                minans = (en - st);
                v.clear();
                v.push_back(st);
                v.push_back(en);
            }
        }
        en++;
    }
    
    return v;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    int temp = arrayA[0];
    int index = 2;
    while(1){
        int flag1 = 0;
        for(int i = 0; i < arrayA.size(); i++){
            if(arrayA[i] % temp != 0){
                flag1 = 1;
                break;
            }
        }
        if(flag1 == 0){
            break;
        }
        else{
            temp = arrayA[0] / index;
            index++;
        }
    }
    int flag2 = 0;
    for(int i = 0; i < arrayB.size(); i++){
        if(arrayB[i] % temp == 0){
            flag2 = 1;
            break;
        }
    }
    if(flag2 == 0){
        answer = temp;
    }
    
    temp = arrayB[0];
    index = 2;
    while(1){
        int flag3 = 0;
        for(int i = 0; i < arrayB.size(); i++){
            if(arrayB[i] % temp != 0){
                flag3 = 1;
                break;
            }
        }
        if(flag3 == 0){
            break;
        }
        else{
            temp = arrayB[0] / index;
            index++;
        }
    }
    flag2 = 0;
    for(int i = 0; i < arrayA.size(); i++){
        if(arrayA[i] % temp == 0){
            flag2 = 1;
            break;
        }
    }
    if(flag2 == 0){
        answer = max(answer, temp);
    }
    return answer;
}
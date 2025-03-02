#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[100001][2];

void func(int target){
    if(arr[target - 60][0] == arr[target - 50][0]){
        arr[target][0] = arr[target - 50][0] + 1;
        arr[target][1] = max(arr[target - 60][1], arr[target - 50][1] + 1);
    }
    else if(arr[target - 60][0] < arr[target - 50][0]){
        arr[target][0] = arr[target - 60][0] + 1;
        arr[target][1] = arr[target - 60][1];
    }
    else{
        arr[target][0] = arr[target - 50][0] + 1;
        arr[target][1] = arr[target - 50][1] + 1;
    }
}

vector<int> solution(int target) {
    vector<int> answer;
    
    for(int i = 1; i <= target; i++){
        if(i == 50 || i <= 20){
            arr[i][0] = 1;
            arr[i][1] = 1;
        }
        
        else if(i <= 60 && i % 3 == 0){
            arr[i][0] = 1;
            arr[i][1] = 0;
        }
        
        else if(i <= 40 && i % 2 == 0){
            arr[i][0] = 1;
            arr[i][1] = 0;
        } 
        
        else if(i > 50 && i <= 70){
            arr[i][0] = 2;
            arr[i][1] = 2;
        }
        else if(i < 70){
            if(i < 40){
                arr[i][0] = 2;
                arr[i][1] = 2;
            }
            else{
                arr[i][0] = 2;
                arr[i][1] = 1;
            }
        }
        else{
            func(i);
        }
    }
    
    answer.push_back(arr[target][0]);
    answer.push_back(arr[target][1]);
    return answer;
}
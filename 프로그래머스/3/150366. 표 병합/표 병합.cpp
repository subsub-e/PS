#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string arr[51][51];
int uf[2501];

int find(int x){
    if(uf[x] == x){
        return x;
    }
    return uf[x] = find(uf[x]);
}

void Union(int x, int y){
    int X = find(x);
    int Y = find(y);
    if(X > Y){
        uf[X] = Y;
    }
    else{
        uf[Y] = X;
    }
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for(int i = 0; i < 2500; i++){
        uf[i] = i;
    }
    
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            arr[i][j] = "EMPTY";
        }
    }
    
    for(auto str : commands){
        vector<string> v;
        string temp = "";
        for(int i = 0; i < str.length(); i++){
            if(str[i] == ' '){
                v.push_back(temp);
                temp = "";
            }
            else{
                temp += str[i];
            }
        }
        v.push_back(temp);
        
        if(v[0] == "UPDATE"){
            if(v.size() == 4){
                int x = stoi(v[1]) - 1;
                int y = stoi(v[2]) - 1;
                int parentIndex = find(x * 50 + y);
                
                for(int i = 0; i < 2500; i++){
                    if(uf[i] == parentIndex){
                        arr[i / 50][i % 50] = v[3];
                    }
                }
            }
            else{
                for(int i = 0; i < 50; i++){
                    for(int j = 0; j < 50; j++){
                        if(arr[i][j] == v[1]){
                            arr[i][j] = v[2];
                        }
                    }
                }
            }
        }
        else if(v[0] == "MERGE"){
            int x1 = stoi(v[1]) - 1;
            int y1 = stoi(v[2]) - 1;
            int x2 = stoi(v[3]) - 1;
            int y2 = stoi(v[4]) - 1;
        
            
            int x1Index = find(50 * x1 + y1);
            int x2Index = find(50 * x2 + y2);
            
            Union(x1Index, x2Index);
            int root = find(x1Index);
            
            string value = "EMPTY";
            if(arr[x1][y1] == "EMPTY" && arr[x2][y2] != "EMPTY"){
                value = arr[x2][y2];
            }
            else{
                value = arr[x1][y1];
            }
            
            
            for(int i = 0; i < 2500; i++){
                if(uf[i] == x1Index || uf[i] == x2Index || uf[i] == root){
                    uf[i] = root;
                    arr[i / 50][i % 50] = value;
                }
            }
        }
        
        else if(v[0] == "UNMERGE"){
            int x = stoi(v[1]) - 1;
            int y = stoi(v[2]) - 1;
            
            string target = arr[x][y];
            
            int parentIndex = find(x * 50 + y);
            
            for(int i = 0; i < 2500; i++){
                if(uf[i] == parentIndex){
                    uf[i] = i;
                    int tempX = i / 50;
                    int tempY = i % 50;
                    
                    arr[tempX][tempY] = "EMPTY";
                }
            }
            
            arr[x][y] = target;
        }
        else{
            int x = stoi(v[1]) - 1;
            int y = stoi(v[2]) - 1;
            answer.push_back(arr[x][y]);
        }
    }
    return answer;
}
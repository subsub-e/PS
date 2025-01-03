#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;

int uf[101];
tuple<int, int, int> arr[10000];

int find(int x){
    if(x == uf[x]){
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

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++){
        uf[i] = i;
    }
    
    for(int i = 0; i < (int) costs.size(); i++){
        int x1, x2, c;
        c = costs[i][2];
        x1 = costs[i][0];
        x2 = costs[i][1];
        arr[i + 1] = make_tuple(c, x1, x2);
    }
    sort(arr + 1, arr + (int) costs.size() + 1);
    
    for(int i = 1; i <= (int) costs.size(); i++){
        int x1, x2, c;
        tie(c, x1, x2) = arr[i];
        if(find(x1) != find(x2)){
            answer += c;
            Union(x1, x2);
        }
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    set<pair<int, int> > s;
    
    for(int i = 0; i < puddles.size(); i++){
        s.insert(make_pair(puddles[i][1], puddles[i][0]));
    }
    
    
    int arr[102][102] = {};
    
    arr[1][1] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == 1 && j == 1){
                continue;
            }
            pair<int, int> temp = make_pair(i, j);
            if(s.find(temp) == s.end()){
                arr[i][j] = ((arr[i-1][j] % 1000000007) + (arr[i][j-1] % 1000000007)) % 1000000007;
            }
            else{
                // cout << temp.first << ' ' << temp.second << '\n';
                arr[i][j] = 0;
            }
        }
    }
    
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    return arr[n][m] % 1000000007;
}
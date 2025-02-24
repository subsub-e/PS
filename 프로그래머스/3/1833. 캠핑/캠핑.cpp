#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


// bool visited[5001];
// vector<int> v;

// void dfs(int now, int siz, vector<vector<int>> &data){
    
//     if(v.size() == 2){
//         int x1 = data[v[0]][0];
//         int y1 = data[v[0]][1];
//         int x2 = data[v[1]][0];
//         int y2 = data[v[1]][1];
        
//         if(x2 == x1 || y2 == y1){
//             return;
//         }
        
//         for(int i = 0; i < siz; i++){
//             if(i == v[0] || i == v[1]){
//                 continue;
//             }
//             if(data[i][0] > min(x1, x2) && data[i][0] < max(x1, x2) && data[i][1] > min(y1, y2) && data[i][1] < max(y1, y2)){
//                 return;
//             }
//         }
        
//         answer++;
//         return;
//     }
    
//     for(int i = now; i < siz; i++){
//         v.push_back(i);
//         dfs(i + 1, siz, data);
//         v.pop_back();
//     }
// }

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    sort(data.begin(), data.end());
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int x1 = data[i][0];
            int y1 = data[i][1];
            int x2 = data[j][0];
            int y2 = data[j][1];
            int flag = 0;
            if(x1 == x2 || y1 == y2){
                continue;
            }
            for(int k = i + 1; k < j; k++){
                int check_x = data[k][0];
                int check_y = data[k][1];
                if(check_x > x1 && check_x < x2 && check_y > min(y1, y2) && check_y < max(y1, y2)){
                    //cout << check_x << ' ' << x1 << ' ' << x2 << ' ' << check_y << ' ' << y1 << ' ' << y2 << '\n';
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                //cout << i << ' ' << j << '\n';
                answer++;
            }
        }
    }
    
    
    return answer;
}
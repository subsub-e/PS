#include <string>
using namespace std;

bool visited[11][11][4];

int solution(string dirs) {
    int answer = 0;
    int x = 5;
    int y = 5;
    for(int i = 0; i < dirs.length(); i++){
        if(dirs[i] == 'L'){
            if(x >= 0 && x < 11 && y-1 >= 0 && y-1 < 11){
                y--;
                if(!visited[x][y][0] && !visited[x][y+1][2]){
                    visited[x][y][0] = 1;
                    visited[x][y+1][2] = 1;
                    answer++;
                }
            }
            else{
                continue;
            }
        }
        if(dirs[i] == 'U'){
            if(x-1 >= 0 && x-1 < 11 && y >= 0 && y < 11){
                x--;
                if(!visited[x][y][1] && !visited[x + 1][y][3]){
                    visited[x][y][1] = 1;
                    visited[x + 1][y][3] = 1;
                    answer++;
                }
            }
            else{
                continue;
            }
        }
        if(dirs[i] == 'R'){
            if(x >= 0 && x < 11 && y+1 >= 0 && y+1 < 11){
                y++;
                if(!visited[x][y][2] && !visited[x][y - 1][0]){
                    visited[x][y][2] = 1;
                    visited[x][y-1][0] = 1;
                    answer++;
                }
            }
            else{
                continue;
            }
        }
        if(dirs[i] == 'D'){
            if(x + 1 >= 0 && x + 1 < 11 && y >= 0 && y < 11){
                x++;
                if(!visited[x][y][3] && !visited[x-1][y][1]){
                    visited[x][y][3] = 1;
                    visited[x-1][y][1] = 1;
                    answer++;
                }
            }
            else{
                continue;
            }
        }
    }
    return answer;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;



int main(){
    int t; cin >> t;
    while(t--){
        int n, m, x, y;
        cin >> m >> n >> x >> y;

        int rx, ry;
        if(x > y){
            rx = x - y + 1;
            ry = 1;
        }
        else{
            ry = y - x + 1;
            rx = 1;
        }
        int cnt = 1;
        int nx = 1;
        int ny = 1;
        bool stop = false; // 멸망해 이거나 정답을 찾았거나
        while(!stop){
            //다음해가 타겟 x와 같은 경우 -> 정답
            if(nx == rx && ny == ry){ 
                cnt = cnt + x - rx; // 정답해로 갈 수 있도록 더해줌
                nx = x;
                ny = y;
                stop = true;
            }        
            else if(m - nx < n - ny){// x가 먼저 1이되는 경우
                ny = ny + m - nx + 1;
                cnt = cnt + m - nx + 1;
                nx = 1;  
            }else if(m - nx > n- ny){ // y가 먼저 1이 되는 경우
                nx = nx + n - ny + 1;
                cnt = cnt + n - ny + 1;
                ny = 1;
            }else{ // 멸망해인 경우
                cnt = cnt + n - ny;
                nx = m;
                ny = n;
                stop = true;
            }
        }
        if(nx == x && ny == y){
            cout << cnt << endl;
        }else{
            cout << -1 << endl;
        }
    }
}
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

string answer = "impossible";
int N, M;

bool calculateDis(int nowx, int nowy, int r, int c, int k, int cnt) {
    int remain = abs(r - nowx) + abs(c - nowy);
    if ((k - cnt - remain) % 2 != 0 || remain > k - cnt) {
        return false;
    }
    return true;
}

void dfs(int nowx, int nowy, int desx, int desy, string ans, int cnt) {
    if(cnt < 0) return;
    if(nowx == desx && nowy == desy && cnt == 0) {
        answer = ans;
        return;
    }
    
    if(answer != "impossible") return; // 이미 사전순 경로를 찾았으면 종료
    
    // 사전 순 탐색: d → l → r → u
    if(nowx + 1 <= N && calculateDis(nowx + 1, nowy, desx, desy, cnt, 1))
        dfs(nowx + 1, nowy, desx, desy, ans + "d", cnt - 1);
    if(nowy - 1 >= 1 && calculateDis(nowx, nowy - 1, desx, desy, cnt, 1))
        dfs(nowx, nowy - 1, desx, desy, ans + "l", cnt - 1);
    if(nowy + 1 <= M && calculateDis(nowx, nowy + 1, desx, desy, cnt, 1))
        dfs(nowx, nowy + 1, desx, desy, ans + "r", cnt - 1);
    if(nowx - 1 >= 1 && calculateDis(nowx - 1, nowy, desx, desy, cnt, 1))
        dfs(nowx - 1, nowy, desx, desy, ans + "u", cnt - 1);
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    N = n;
    M = m;
    int dist = abs(x - r) + abs(y - c);
    
    if (k < dist || (k - dist) % 2 != 0) {
        return "impossible";
    }
    
    dfs(x, y, r, c, "", k);
    
    return answer;
}

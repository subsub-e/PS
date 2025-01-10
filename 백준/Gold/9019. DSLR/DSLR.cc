#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;



int t;
bool visited[10001];


int func1(int x){
    return x * 2 % 10000;
}

int func2(int x){
    if(x == 0){
        return 9999;
    }
    return x - 1;
}

int func3(int x){
    int l = x % 1000;
    int r = x / 1000;
    return l * 10 + r;
}

int func4(int x){
    int l = x % 10;
    int r = x / 10;
    return l * 1000 + r;
}

string solution(int st, int en){
    memset(visited, 0, sizeof(visited));
    queue<pair<int, string> > q;
    q.push(make_pair(st, ""));
    visited[st] = 1;

    while(!q.empty()){
        int now = q.front().first;
        string ans = q.front().second;
        q.pop();

        if(now == en){
            return ans;
        }

        int temp = func1(now);
        if (!visited[temp]) {
            visited[temp] = true;
            q.push({temp, ans + "D"});
        }
        //cout << temp << '\n';
        temp = func2(now);
        if (!visited[temp]) {
            visited[temp] = true;
            q.push({temp, ans + "S"});
        }
        //cout << temp << '\n';
        temp = func3(now);
        if (!visited[temp]) {
            visited[temp] = true;
            q.push({temp, ans + "L"});
        }
        //cout << temp << '\n';
        temp = func4(now);
        if (!visited[temp]) {
            visited[temp] = true;
            q.push({temp, ans + "R"});
        }
        //cout << temp << '\n';
    }
}

int main(){
    cin >> t;
    while(t--){
        int str1, str2;
        cin >> str1 >> str2;
        cout << solution(str1, str2) << '\n';
    }
}
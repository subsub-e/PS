#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int st, en;
int cnt[200003];
queue<pair<int, int> > q;
int ans = 0;
const int INF = 1e9 + 10;

void bfs(){
    while(!q.empty()){
        int now = q.front().first;
        int c = q.front().second;
        q.pop();

        if(now == en){
            ans++;
            continue;
        }

        if(cnt[en] < c){
            return;
        }

        if(cnt[now-1] >= c + 1 && now - 1 >= 0){
            q.push(make_pair(now - 1, c + 1));
            cnt[now - 1] = c + 1;
        }

        if(cnt[now + 1] >= c + 1 && now + 1 <= 100000){
            q.push(make_pair(now + 1, c + 1));
            cnt[now + 1] = c + 1;
        }

        if(cnt[now * 2] >= c + 1 && now * 2 <= 100000){
            q.push(make_pair(now * 2, c + 1));
            cnt[now * 2] = c + 1;
        }

    }
}


int main(){
    cin >> st >> en;

    fill(cnt, cnt + 200002, INF);

    q.push(make_pair(st, 0));
    cnt[st] = 0;
    bfs();

    cout << cnt[en] << '\n' << ans;
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int s;
int now = 1;
queue<tuple<int, int, int> > q;
bool visited[10001][10001];

void bfs(){
    while(!q.empty()){
        int screen, clip, cnt;
        tie(screen, clip, cnt) = q.front();
        q.pop();

        if(visited[screen][clip]){
            continue;
        }
        if(screen == s){
            cout << cnt;
            exit(0);
        }
        visited[screen][clip] = 1;

        q.push(make_tuple(screen, screen, cnt + 1));
        if(clip > 0){
            q.push(make_tuple(screen + clip, clip, cnt + 1));
        }
        if(screen > 1){
            q.push(make_tuple(screen - 1, clip, cnt + 1));
        }
    }
}

int main(){
    cin >> s;
    q.push(make_tuple(1, 0, 0));
    bfs();
}   
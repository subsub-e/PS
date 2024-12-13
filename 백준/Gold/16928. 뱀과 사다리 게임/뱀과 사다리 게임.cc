#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int arr[101];
queue<int> q;
bool visited[101];
vector<pair<int, int> > v;

bool cango(int x){
    return 1 < x && x <= 100 && !visited[x];
}

void bfs(){
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i = 1; i <= 6; i++){
            int nxt = now + i;
            if(cango(nxt)){
                int temp = 0;
                int temp1 = 0;
                for(int j = 0; j < v.size(); j++){
                    if(nxt == v[j].first){
                        if(visited[v[j].second]){
                            temp1 = 1;
                            break;
                        }
                        temp = 1;
                        arr[v[j].second] = arr[now] + 1;
                        q.push(v[j].second);
                        visited[v[j].second] = 1;
                    }
                }
                if(temp == 0 && temp1 == 0){
                    q.push(nxt);
                    visited[nxt] = 1;
                    arr[nxt] = arr[now] + 1;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    while(n--){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    while(m--){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    q.push(1);
    visited[1] = 1;

    bfs();

    cout << arr[100];
}
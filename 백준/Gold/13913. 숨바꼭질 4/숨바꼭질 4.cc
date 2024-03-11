#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int n, m;
queue<pair<int, int> > q;
vector<int> v;
bool visited[100001];
int counted[100001];
int dx[3] = {-1, 1, 2};

int bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        //cout << x << ' ' << y << '\n';
        q.pop();
        

        if(x == m){
            int index = x;
            while(index != n){
                v.push_back(index);
                index = counted[index];
            }
            v.push_back(n);
            return y;
        }
        for(int i = 0; i < 3; i++){
            int nx = x;
            if(i == 2){
                nx *= 2;
            }
            else if(i == 0 || i == 1){
                nx += dx[i];
            }  
            //cout << nx << '\n';

            if(0 <= nx && nx < 100001 && !visited[nx]){

                visited[nx] = 1;
                q.push(make_pair(nx, y + 1));
                counted[nx] = x;
            }
        }
    }
}


int main()
{
    cin >> n >> m;

    q.push(make_pair(n, 0));
    visited[n] = 1;

    cout << bfs() << '\n';

    for(int i = v.size() - 1; i >= 0; i--){
        cout << v[i] << ' ';
    }
    return 0;
}
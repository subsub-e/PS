#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
#include <queue>

using namespace std;

int n, m, k;
int arr[11][11];
vector<pair<int, int> > v;
bool visited[11][11];
int maxans = INT_MIN;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void func(int x, int y){
    if(v.size() == k){
        int sum = 0;
        for(int i = 0; i < v.size(); i++){
            sum += arr[v[i].first][v[i].second];
        }
        maxans = max(maxans, sum);
        return;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((i <= x && j <= y) && (i != 0 && j != 0)){
                continue;
            }
            int flag = 0;
            for(int t = 0; t < 4; t++){
                int nx = i + dx[t];
                int ny = j + dy[t];
                if(0 <= nx && nx < n && 0 <= ny && ny < m){
                    if(visited[nx][ny]){
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 0){
                if(!visited[i][j]){
                    visited[i][j] = 1;
                    v.push_back(make_pair(i, j));
                    func(i, j);
                    v.pop_back();
                    visited[i][j] = 0;
                }
                
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    func(0, 0);

    cout << maxans;
	return 0;
}
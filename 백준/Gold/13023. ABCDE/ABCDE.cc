#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<int> v[2001];
bool visited[2001];
int flag = 0;

void dfs(int x, int cnt){
    if(flag == 1){
        return;
    }

    if(cnt >= 4){
        flag = 1;
    }
    
    for(auto next : v[x]){
        if(!visited[next]){
            visited[next] = 1;
            dfs(next, cnt + 1);
            visited[next] = 0;
        }
    }

    return;
}

int main() {
	
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }

    for(int i = 0; i < n; i++){
        visited[i] = 1;
        dfs(i, 0);
        visited[i] = 0;
    }
    

    if(flag == 1){
        cout << 1;
    }
    else{
        cout << 0;
    }

	return 0;
}
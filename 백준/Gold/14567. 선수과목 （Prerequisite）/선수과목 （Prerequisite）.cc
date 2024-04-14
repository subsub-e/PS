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

int n, m;
vector<vector<int> > v(1001);
int indeg[1001];
queue<int> q;
int dp[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        indeg[x2]++;
    }

    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            q.push(i);
            dp[i] = 1;
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto next : v[cur]){
            indeg[next]--;
            if(indeg[next] == 0){
                q.push(next);
                dp[next] = dp[cur] + 1;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << dp[i] << ' ';
    }
	return 0;
}
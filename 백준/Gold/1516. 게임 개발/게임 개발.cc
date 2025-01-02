#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n; 
vector<int> v[501];
vector<int> indeg(501);
int answer[502];
int weight[502];

void topologySort(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            q.push(i);
            answer[i] = weight[i];
        }
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto next : v[now]){
            indeg[next]--;
            answer[next] = max(answer[next], answer[now] + weight[next]);
            if(indeg[next] == 0){
                q.push(next);
            }
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        int w; cin >> w;
        weight[i] = w;

        while(1){
            int prev; cin >> prev;
            if(prev == -1){
                break;
            }
            v[prev].push_back(i);
            indeg[i]++;
        }
    }

    topologySort();

    for(int i = 1; i <= n; i++){
        cout << answer[i] << '\n';
    }
}
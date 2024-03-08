#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool visited[501];
vector<int> v[501];



bool IsTree(int now, int level){
    visited[now] = 1;
    for(auto next : v[now]){
        if(next == level){
            continue;
        }
        if(visited[next]){
            
            return false;
        }
        if(IsTree(next, now) == false){
            //cout << now << ' ' << level << '\n';
            return false;
        }
    }
    return true;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int index = 1;
    while(1){
        int u, ver;
        cin >> u >> ver;
        if(u == 0 && ver == 0){
            break;
        }
        for(int i = 1; i <= u; i++){
            v[i].clear();
            visited[i] = 0;
        }

        for(int i = 0; i < ver; i++){
            int x1, x2; 
            cin >> x1 >> x2;
            v[x1].push_back(x2);
            v[x2].push_back(x1);
        }

        

        int cnt = 0;
        for(int i = 1; i <= u; i++){
            if(!visited[i]){
                if(IsTree(i, 0)){
                    cnt++;
                }
            }
        }

        if(cnt == 1){
            cout << "Case " << index << ": There is one tree." << '\n';
        }
        else if(cnt == 0){
            cout << "Case " << index << ": No trees." << '\n';
        }
        else{
            cout << "Case " << index << ": A forest of " << cnt << " trees." << '\n';
        }
        index++;
    }
    
    return 0;
}
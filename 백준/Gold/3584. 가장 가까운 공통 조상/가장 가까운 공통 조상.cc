#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int t, m;
vector<int> v[10002];
int parent[10002], level[10002];
bool visited[10002];
bool check[10002];


int findRoot(int s){
    for(int i = 1; i <= s; i++){
        if(!check[i]){
            return i;
        }
    }
}

int lca(int left, int right){
    while(level[left] != level[right]){
        if(level[left] > level[right]){
            left = parent[left];
        }
        else{
            right = parent[right];
        }
    }

    while(left != right){
        left = parent[left];
        right = parent[right];
    }
    
    return left;
}

void set_tree(int now, int pnode){
    visited[now] = 1;
    parent[now] = pnode;
    level[now] = level[pnode] + 1;

    for(auto next : v[now]){
        if(!visited[next]){
            set_tree(next, now);
        }
    }
}

int init(){
    for (int i = 0; i < 10002; ++i) {
        v[i].clear();
    }

    fill(parent, parent + m + 1, 0);
    fill(level, level + m + 1, 0);
    fill(visited, visited + m + 1, 0);
    fill(check, check + m + 1, 0);
    
    for(int i = 0; i < m - 1; i++){
        int st, en;
        cin >> st >> en;
        v[st].push_back(en);
        check[en] = 1;
    }

    return findRoot(m);
}

int main(){
    cin >> t;
    while(t--){
        cin >> m;
        
        int root = init();

        set_tree(root, 0);

        int st, en;
        cin >> st >> en;
        
        cout << lca(st, en) << '\n';

    }
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


vector<int> v[100001];
int n, parent[100001], level[100001];
bool visited[100001];

int solution(int left, int right){
    while(level[left] != level[right]){
        if(level[left] > level[right]){
            left = parent[left];
        }
        else{
            right = parent[right];
        }
    }
    //cout << level[left] << ' ' << level[right] << '\n';

    while(left != right){
        right = parent[right];
        left = parent[left];
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

void init(){
    for(int i = 0; i < n-1; i++){
        int st, en;
        cin >> st >> en;
        v[st].push_back(en);
        v[en].push_back(st);
    }
}

int main(){
    cin >> n;
    
    init();
    set_tree(1, 0);

    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int st, en;
        cin >> st >> en;
        cout << solution(st, en) << '\n';
    }
}
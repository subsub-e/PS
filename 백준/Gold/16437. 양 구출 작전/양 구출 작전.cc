#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


long long n, answer;
long long arr[123457];
long long parent[123457];
long long level[123457];
bool visited[123457];
vector<pair<int, int> > v;
vector<int> tree[123457];

void solution(int now, long long weight){
    //cout << now << ' ' << weight << '\n';
    if(weight <= 0){
        return;
    }

    arr[parent[now]] += weight;    
}

void set_tree(int now, int now_level){
    level[now] = now_level;
    for(auto next : tree[now]){
        set_tree(next, now_level + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 2; i <= n; i++){
        char c;
        long long m, road;
        cin >> c >> m >> road;
        if(c == 'W'){
            arr[i] = -m;
        }
        else{
            arr[i] = m;
        }
        parent[i] = road;
        tree[road].push_back(i);
    }

    set_tree(1, 0);

    for(int i = 1; i <= n; i++){
        v.push_back(make_pair(level[i], i));
    }

    sort(v.rbegin(), v.rend());

    for(int i = 0; i < (int)v.size(); i++){
        solution(v[i].second, arr[v[i].second]);
    }

    // for(int i = 1; i <= n; i++){
    //     cout << arr[i] << '\n';
    // }

    cout << arr[1];
}
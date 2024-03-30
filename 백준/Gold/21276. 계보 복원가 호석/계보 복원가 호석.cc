#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
#include <map>
#include <set>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    map<string, int> m;
    vector<vector<int> > v(n + 1);
    vector<int> indig(n + 1);
    queue<int> q;
    set<string> s[1001];
    string no[1001];
    for(int i = 1; i <= n; i++){
        string str; cin >> str;
        m[str] = i;
        no[i] = str;
    }

    int k; cin >> k;
    for(int i = 0; i < k; i++){
        string str1, str2; cin >> str1 >> str2;
        v[m[str2]].push_back(m[str1]);
        indig[m[str1]]++;
    }

    vector<string> parent;
    for(int i = 1; i <= n; i++){
        if(indig[i] == 0){
            q.push(i);
            parent.push_back(no[i]);
        }
    }

    cout << parent.size() << '\n';
    sort(parent.begin(), parent.end());
    for(int i = 0; i < parent.size(); i++){
        cout << parent[i] << ' ';
    }
    cout << '\n';

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto next : v[cur]){
            if(--indig[next] == 0){
                s[cur].insert(no[next]);
                q.push(next);
            }
        }
    }

    for(auto cur : m){
        cout << cur.first << ' ';
        cout << s[cur.second].size() << ' ';
        for(auto next : s[cur.second]){
            cout << next << ' ';
        }
        cout << '\n';
    }
    return 0;
}
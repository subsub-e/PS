#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    set<string> s1;
    set<string> s2;
    int n, m;
    cin >> n >> m;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        s1.insert(str);
    }

    for(int i = 0; i < m; i++){
        cin >> str;
        s2.insert(str);
    }

    int cnt = 0;
    vector<string> v;
    for(auto iter : s1){
        if(s2.find(iter) != s2.end()){
            cnt++;
            v.push_back(iter);
        } 
    }
    cout << cnt << '\n';
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << '\n';
    }
}
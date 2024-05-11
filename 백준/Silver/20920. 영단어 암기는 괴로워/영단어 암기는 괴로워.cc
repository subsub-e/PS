#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;


bool comp(pair<string, int> a, pair<string, int> b){
    if(a.second == b.second){
        if(a.first.length() == b.first.length()){
            return a.first < b.first;
        }
        else{
            return a.first.length() > b.first.length();
        }
    }
    else{
        return a.second > b.second;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<string, int> m;
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        if(str.length() >= k){
            m[str]++;
        }
    }

    vector<pair<string, int> > v;
    for(auto itr : m){
        v.push_back(make_pair(itr.first, itr.second));
    }

    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i].first << ' ' << v[i].second << '\n';
    // }

    sort(v.begin(), v.end(), comp);

    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << '\n';
    }

    return 0;
}
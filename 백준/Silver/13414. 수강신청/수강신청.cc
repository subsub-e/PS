#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    unordered_map<string, int> m;
    vector<pair<int, string> > v;
    int n, p;
    cin >> n >> p;
    for(int i = 0; i < p; i++){
        string str;
        cin >> str;
        m[str] = i;
    }

    for(auto i : m){
        string ke = i.first;
        int p = i.second;
        v.push_back(make_pair(p, ke));
    }

    sort(v.begin(), v.end());
    int cnt = 0;

    for(int i = 0; i < min(n, (int) v.size()); i++){
        cout << v[i].second << '\n';
    }
}
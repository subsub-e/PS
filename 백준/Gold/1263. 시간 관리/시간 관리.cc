#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool comp(pair<int, int>&a, pair<int, int>&b){
    return a.second > b.second;
}

int main() {
	
    int n; cin >> n;
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++){
        int t, s;
        cin >> t >> s;
        v.push_back(make_pair(t, s));
    }

    sort(v.begin(), v.end(), comp);
    int start = (v[0].second - v[0].first);

    for(int i = 1; i < n; i++){
        
        if((start - v[i].first) < 0){
            cout << -1;
            return 0;
        }
        else{
            if(start > v[i].second){
                start = (v[i].second - v[i].first);
            }
            else{
                start -= v[i].first;
            }
        }
        //cout << start << '\n';
    }
    if(start < 0){
        cout << -1;
            return 0;
    }
    cout << start;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    vector<pair<int, int> > v;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v.push_back(make_pair(x1, x2));
    }

    sort(v.begin(), v.end());
   
    for(int i = 0; i < n; i++){
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
	return 0;
}
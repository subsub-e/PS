#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        vector<pair<int, int> > v;
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int x1, x2; cin >> x1 >> x2;
            v.push_back(make_pair(x1, x2));
        }
        sort(v.begin(), v.end());

        int temp = v[0].second;
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(v[i].second < temp){
                cnt++;
                temp = v[i].second;
            }
        }

        cout << cnt << '\n';
    }
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int arr[201][201];



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        fill(arr[i], arr[i] + 1 + n, INF);
    }
    
    for(int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int x, y, cost;
        cin >> x >> y >> cost;
        arr[x][y] = min(arr[x][y], cost);
    }


    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    int t; cin >> t;
    vector<int> v;
    for(int i = 0; i < t; i++){
        int tx; cin >> tx;
        v.push_back(tx);
    }

    vector<int> ans;
    int minans = INT_MAX;
    for(int i = 1; i <= n; i++){
        int maxans = 0;
        for(int j = 0; j < v.size(); j++){
            maxans = max(maxans, arr[i][v[j]] + arr[v[j]][i]);
        }
        if(maxans < minans){
            ans.clear();
            ans.push_back(i);
            minans = maxans;
        }
        else if(maxans == minans){
            ans.push_back(i);
        }
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
	return 0;
}
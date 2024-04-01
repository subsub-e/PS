#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int n, m;
int arr[51];


int find(int x){
    if(arr[x] == x){
        return x;
    }
    return arr[x] = find(arr[x]);
}

void Union(int x, int y){
    int pos_x = find(x);
    int pos_y = find(y);
    if(pos_x != pos_y){
        arr[pos_x] = pos_y;
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    vector<vector<int> > v(m + 1);
    for(int i = 0; i <= n; i++){
        arr[i] = i;
    }

    int k; cin >> k;
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        Union(x, 0);
    }

    for(int i = 0; i < m; i++){
        int t; cin >> t;
        for(int j = 0; j < t; j++){
            int x1; cin >> x1;
            v[i].push_back(x1);
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 1; j < v[i].size(); j++){
            Union(v[i][j], v[i][j - 1]);
        }
    }

    int cnt = 0;
    //  for(int i = 0; i < m; i++){
    //     for(int j = 0; j < v[i].size(); j++){
    //         cout << v[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for(int i = 0; i < m; i++){
        int flag = 0;
        for(int j = 0; j < v[i].size(); j++){
            if(find(0) == find(v[i][j])){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cnt++;
        }
    }

    cout << cnt;



	return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
using namespace std;


int n, m;
int arr[1001];

int find(int x){
    if(arr[x] == x){
        return x;
    }
    return arr[x] = find(arr[x]);
}

void Union(int x, int y){
    int X = find(x);
    int Y = find(y);
    arr[X] = Y;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int k; cin >> k;
    while(k--){
        memset(arr, 0, sizeof(arr));
        
        cin >> n >> m;
        pair<int, int> v[m + 1];
        int cnt = 0;

        for(int i = 1; i <= n; i++){
            arr[i] = i;
        }

        for(int i = 1; i <= m; i++){
            int x1, x2;
            cin >> x1 >> x2;
            v[i] = make_pair(x1, x2);
        }

        //sort(v + 1, v + 1 + m);

        for(int i = 1; i <= m; i++){
            int x = v[i].first;
            int y = v[i].second;
            if(find(x) != find(y)){
                cnt++;
                Union(x, y);
            }
        }
        cout << cnt << '\n';
    }

	return 0;
}
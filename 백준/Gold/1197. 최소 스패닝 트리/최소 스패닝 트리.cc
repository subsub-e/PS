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
int uf[10001];
tuple<int, int, int> arr[100001];

int find(int x){
    if(uf[x] == x){
        return x;
    }
    return uf[x] = find(uf[x]);
}

void Union(int x, int y){
    int X = find(x);
    int Y = find(y);
    if(X != Y){
        uf[X] = Y;
    }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        uf[i] = i;
    }

    for(int i = 1; i <= m; i++){
        int x1, x2, cost;
        cin >> x1 >> x2 >> cost;
        arr[i] = make_tuple(cost, x1, x2);
    }

    sort(arr + 1, arr + 1 + m);

    int sum = 0;
    for(int i = 1; i <= m; i++){
        int x1, x2, cost;
        tie(cost, x1, x2) = arr[i];
        if(find(x1) != find(x2)){
            sum += cost;
            Union(x1, x2);
        }
    }

    cout << sum;
	return 0;
}
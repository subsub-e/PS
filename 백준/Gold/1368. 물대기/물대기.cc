#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
using namespace std;

int n;
int uf[302];
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
    uf[X] = Y;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n + 1; i++){
        uf[i] = i;
    }

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        arr[i] = make_tuple(x, n + 1, i); 
    }

    int p[n + 1][n + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> p[i][j];
        }
    }

    int index = n + 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i < j){
                arr[index] = make_tuple(p[i][j], i, j);
                index++;
            }
        }
    }

    sort(arr + 1, arr + n + 1 + (n - 1) * (n - 2));

    int sum = 0;
    for(int i = 1; i <= n + 1 + (n - 1) * (n - 2); i++){
        int cost, x1, x2;
        tie(cost, x1, x2) = arr[i];
        if(find(x1) != find(x2)){
            sum+=cost;
            Union(x1, x2);
        }
    }

    cout << sum;

	return 0;
}
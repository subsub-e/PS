#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
using namespace std;

tuple<int, int, int> arr[2000001];
int uf[1001];
int n;

int find(int x){
    if(uf[x] == x){
        return x;
    }
    return uf[x] = find(uf[x]);
}

void Union(int x, int y){
    int X = find(x);
    int Y = find(y);
    if (X < Y) uf[Y] = X;
    else uf[Y] = X;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        uf[i] = i;
    }

    int temp[n + 1][n + 1];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> temp[i][j];
        }
    }
    if(n == 1){
        cout << temp[1][1];
        return 0;
    }

    int index = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i < j){
                arr[index] = make_tuple(temp[i][j], i, j);
                index++;
            }
        }
    }

    sort(arr + 1, arr + 1 + (n * (n - 1)) / 2);

    long long sum = 0;
    for(int i = 1; i <= 1 + (n * (n - 1)) / 2; i++){
        int cost, x, y;
        tie(cost, x, y) = arr[i];
        if(find(x) != find(y)){
            sum += cost;
            Union(x, y);
        }
    }

    cout << sum;

	return 0;
}
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
#include <map>
using namespace std;

tuple<double, double, double> arr[10001];
int n;
double uf[101];
double temp[101][2];

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        uf[i] = i;
    }

    for(int i = 1; i <= n; i++){
        double x, y;
        cin >> x >> y;
        temp[i][0] = x;
        temp[i][1] = y;
    }

    int index = 1;

    for(int i = 1; i <= n-1; i++){
        for(int j = i + 1; j <= n; j++){
            double cost = sqrt(((temp[j][1] - temp[i][1]) * (temp[j][1] - temp[i][1])) + ((temp[j][0] - temp[i][0]) * (temp[j][0] - temp[i][0])));
            arr[index++] = make_tuple(cost, i, j);
        }
    }
    sort(arr, arr + index);
    double sum = 0;

    for(int i = 1; i < index; i++){
        double x, y, cost;
        tie(cost, x, y) = arr[i];

        if(find(x) != find(y)){
            sum += cost;
            Union(x, y);
        }
    }

    cout << fixed;
    cout.precision(2);

    cout << sum;

	
	
	return 0;
}
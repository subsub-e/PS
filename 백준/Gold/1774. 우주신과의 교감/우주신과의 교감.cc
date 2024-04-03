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
vector<pair<double, pair<double, double> > > v;
vector<pair<int, int> > arr;
int uf[1001];

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

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        uf[i] = i;
    }

    for(int i = 0; i < n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        arr.push_back(make_pair(x1, x2));
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            int x1 = arr[i].first;
            int y1 = arr[i].second;
            int x2 = arr[j].first;
            int y2 = arr[j].second;
            double cost = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
            v.push_back(make_pair(cost, make_pair(i + 1, j + 1)));
        }
    }

    for(int i = 0; i < m; i++){
        int x1, y1;
        cin >> x1 >> y1;
        Union(x1, y1);
    }

    sort(v.begin(), v.end());

    double sum = 0;

    for(int i = 0; i < v.size(); i++){
        double cost = v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;
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
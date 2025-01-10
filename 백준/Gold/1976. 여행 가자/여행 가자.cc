#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int n, m;
int arr[201][201];
const int INF = 1e9 + 10;

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0){
                arr[i][j] = INF;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k]+ arr[k][j]);
            }
        }
    }

    vector<int> v;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    for(int i = 1; i < m; i++){
        if(arr[v[i-1]][v[i]] == INF){
            cout << "NO";
            return 0;
        }
    }   

    cout << "YES";

}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int arr[12][12];
int maxans = 0;
bool visited[12];


void func(int x, int sum){
    if(x == 11){
        maxans = max(maxans, sum);
        return;
    }

    for(int i = 0; i < 11; i++){
        if(arr[x][i] != 0 && !visited[i]){
            visited[i] = 1;
            func(x + 1, sum + arr[x][i]);
            visited[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    while(n--){
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        maxans = 0;
        for(int i = 0; i < 11; i++){
            for(int j = 0; j < 11; j++){
                cin >> arr[i][j];
            }
        }


        func(0, 0);

        cout << maxans << '\n';
    }
    return 0;
}
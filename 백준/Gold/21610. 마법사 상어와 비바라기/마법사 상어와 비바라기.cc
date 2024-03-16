#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int n, m;
int arr[51][51];
int cloud[51][51];
int dx[4] = {-1, 1, 1, -1};
int dy[4] = {-1, -1, 1, 1};


void simulate(int a, int b){
    // cout << a << ' ' << b << '\n';

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << cloud[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    b = b % n;

    int temp[51][51] = {};
    if(a == 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(cloud[i][j]){
                    //cout << i << ' ' << (j + n - b) % n << '\n';
                    temp[i][(j + n - b) % n] = 1;
                }
            }
        }
    }
    else if(a == 2){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(cloud[i][j]){
                    temp[(i + n - b) % n][(j + n - b) % n] = 1;
                }
            }
        }
    }
    else if(a == 3){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(cloud[i][j]){
                    temp[(i + n - b) % n][j] = 1;
                }
            }
        }
    }
    else if(a == 4){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(cloud[i][j]){
                    temp[(i + n - b) % n][(j + b) % n] = 1;
                }
            }
        }
    }
    else if(a == 5){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(cloud[i][j]){
                    temp[i][(j + b) % n] = 1;
                }
            }
        }
    }
    else if(a == 6){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(cloud[i][j]){
                    temp[(i + b) % n][(j + b) % n] = 1;
                }
            }
        }
    }
    else if(a == 7){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(cloud[i][j]){
                    temp[(i + b) % n][j] = 1;
                }
            }
        }
    }
    else if(a == 8){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(cloud[i][j]){
                    temp[(i + b) % n][(j + n - b) % n] = 1;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(temp[i][j]){
                cloud[i][j] = 1;
            }
            else{
                cloud[i][j] = 0;
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << cloud[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cloud[i][j]){
                arr[i][j]++;
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cloud[i][j] = 0;
    //     }
    // }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cloud[i][j]){
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(0 <= nx && nx < n && 0 <= ny && ny < n && arr[nx][ny] > 0){
                        arr[i][j]++;
                    }
                }
            }
        }
    }

    int next_cloud[51][51] = {};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] >= 2 && cloud[i][j] == 0){
                next_cloud[i][j] = 1;
                arr[i][j] -= 2;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(next_cloud[i][j]){
                cloud[i][j] = 1;
            }
            else{
                cloud[i][j] = 0;
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';


}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    cloud[n-1][0] = 1;
    cloud[n-1][1] = 1;
    cloud[n-2][0] = 1;
    cloud[n-2][1] = 1;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        simulate(a, b);
    }

    int sum = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum += arr[i][j];
        }
    }

    cout << sum;
	return 0;
}
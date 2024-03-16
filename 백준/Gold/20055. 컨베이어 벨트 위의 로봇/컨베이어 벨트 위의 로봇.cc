#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int arr1[n];
    int arr2[n];
    int robot[101] = {};

    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr2[n-i-1] = x;
    }

    // for(int i = 0; i < n; i++){
    //     cout << arr1[i] << ' ';
    // }
    // cout << '\n';
    // for(int i = 0; i < n; i++){
    //     cout << arr2[i] << ' ';
    // }

    int robot_cnt = 1;
    int t = 0;
    while(1){
        t++;
        // cout << t << '\n';
        // for(int i = 0; i < n; i++){
        //     cout << arr1[i] << ' ';
        // }
        // cout << '\n';
        // for(int i = 0; i < n; i++){
        //     cout << arr2[i] << ' ';
        // }
        // cout << '\n';
        // for(int i = 0; i < n; i++){
        //     cout << robot[i] << ' ';
        // }
        // cout << '\n';
        int temp1[n];
        int temp2[n];
        for(int i = 0; i < n-1; i++){
            temp1[i + 1] = arr1[i];
        }
        temp1[0] = arr2[0];
        for(int i = 1; i < n; i++){
            temp2[i-1] = arr2[i];
        }
        temp2[n-1] = arr1[n-1];

        for(int i = 0; i < n; i++){
            arr1[i] = temp1[i];
        }
        for(int i = 0; i < n; i++){
            arr2[i] = temp2[i];
        }

        for(int i = n-1; i > 0; i--){
            robot[i] = robot[i - 1];
        }
        robot[0] = 0;

        if(robot[n-1] > 0){
            robot[n-1] = 0;
        }

        


        for(int j = n - 2; j >= 0; j--){
            if(robot[j] != 0 && robot[j + 1] == 0 && arr1[j + 1] >= 1){
                robot[j + 1] = robot[j];
                robot[j] = 0;
                arr1[j + 1]--;
            }
        }

        if(robot[n-1] > 0){
            robot[n-1] = 0;
        }

        if(arr1[0] > 0){
            robot[0] = robot_cnt;
            robot_cnt++;
            arr1[0]--;
        }

        // for(int i = 0; i < n; i++){
        //     cout << arr1[i] << ' ';
        // }
        // cout << '\n';
        // for(int i = 0; i < n; i++){
        //     cout << arr2[i] << ' ';
        // }
        // cout << '\n';

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(arr1[i] == 0){
                cnt++;
            }
            if(arr2[i] == 0){
                cnt++;
            }
        }
        if(cnt >= m){
            cout << t;
            return 0;
        }
    }
	return 0;
}
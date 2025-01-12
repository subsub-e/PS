#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001][3];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    int temp1 = arr[0][0];
    int temp2 = arr[0][1];
    int temp3 = arr[0][2];

    for(int i = 1; i <= n; i++){
        int temp4 = max(temp1, temp2) + arr[i][0];
        int temp5 = max(temp1, max(temp2, temp3)) + arr[i][1];
        int temp6 = max(temp2, temp3) + arr[i][2];
        temp1 = temp4;
        temp2 = temp5;
        temp3 = temp6;
    }

    int max_temp = max(temp1, max(temp2, temp3));

    temp1 = arr[0][0];
    temp2 = arr[0][1];
    temp3 = arr[0][2];

    for(int i = 1; i <= n; i++){
        int temp4 = min(temp1, temp2) + arr[i][0];
        int temp5 = min(temp1, min(temp2, temp3)) + arr[i][1];
        int temp6 = min(temp2, temp3) + arr[i][2];
        temp1 = temp4;
        temp2 = temp5;
        temp3 = temp6;
    }

    int min_temp = min(temp1, min(temp2, temp3));



    cout << max_temp << ' ' << min_temp;
}

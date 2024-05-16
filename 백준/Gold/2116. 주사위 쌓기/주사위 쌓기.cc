#include <iostream>
#include <algorithm>
#include <climits>
#include <set>
#include <vector>
#include <string>
using namespace std;


int arr[10001][6];

int func(int x){
    if(x == 0){
        return 5;
    }
    else if(x == 1){
        return 3;
    }
    else if(x == 2){
        return 4;
    }
    else if(x == 3){
        return 1;
    }
    else if(x == 4){
        return 2;
    }
    else{
        return 0;
    }
}

int calc(int x1, int x2, int index){
    int maxans = 0;
    for(int i = 1; i <= 6; i++){
        if(i == arr[index][x1] || i == arr[index][x2]){
            continue;
        }
        maxans = max(maxans, i);
    }
    return maxans;
}

int func1(int x, int index){
    for(int i = 0; i < 6; i++){
        if(x == arr[index][i]){
            return i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int maxans = 0;
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < 6; i++){
        int sum = 0;
        int downIndex = i;
        int upIndex = func(i);
        sum += calc(downIndex, upIndex, 0);
        //cout << i << '\n';
        for(int j = 1; j < n; j++){
            int temp = arr[j - 1][upIndex];
            downIndex = func1(temp, j);
            upIndex = func(downIndex);
            //cout << temp << ' ' << downIndex << ' ' << upIndex << '\n';
            sum += calc(downIndex, upIndex, j);
        }
        //cout << sum << '\n';
        if(maxans < sum){
            //cout << i << ' ' << sum << '\n';
            maxans = sum;
        }
        //maxans = max(maxans, sum);
    }

    cout << maxans;

    return 0;
}
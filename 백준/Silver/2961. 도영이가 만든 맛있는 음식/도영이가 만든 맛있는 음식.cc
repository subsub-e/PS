#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
#include <queue>

using namespace std;

int arr[11][2];
int n;
int minans = INT_MAX;
vector<int> v;

void func(int now, int size){
    if(v.size() == size){
        int bit = 1;
        int del = 0;
        for(int i = 0; i < size; i++){
            bit *= arr[v[i]][0];
            del += arr[v[i]][1];
        }
        minans = min(minans, abs(bit - del));
        return;
    }


    for(int i = now; i < n; i++){
        v.push_back(i);
        func(i + 1, size);
        v.pop_back();
    }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i = 0; i < n; i++){
        minans = min(minans, abs(arr[i][0] - arr[i][1]));
    }

    for(int i = 2; i <= n; i++){
        func(0, i);
    }

    cout << minans;

    

	return 0;
}
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

int arr[21][21];
int minans = INT_MAX;
vector<int> v;
vector<int> v1;
int n;

void func(int now, int size){
    // if(minans == 0){
    //     return;
    // }
    if(v.size() == size){
        int sum1 = 0;
        int sum2 = 0;
        v1.clear();
        int index = 0;
        for(int i = 0; i < n; i++){
            if(index >= v.size()){
                v1.push_back(i);
                continue;
            }
            if(i == v[index]){
                index++;
                continue;
            }
            v1.push_back(i);
        }
        
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                sum1 += (arr[v[i]][v[j]] + arr[v[j]][v[i]]);
            }
        }

        for(int i = 0; i < v1.size(); i++){
            for(int j = i + 1; j < v1.size(); j++){
                sum2 += (arr[v1[i]][v1[j]] + arr[v1[j]][v1[i]]);
            }
        }

        //cout << sum1 << ' ' << sum2 << '\n';
        minans = min(minans, abs(sum2 - sum1));
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
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n / 2; i++){
        func(0, i);
    }
    
    cout << minans;
	return 0;
}
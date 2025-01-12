#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, maxans;
vector<int> v;

int game(int x1, int x2){
    int temp_max = 0;
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(v[i] != x1 && v[i] != x2){
            temp_max = max(temp_max, cnt);
            cnt = 0;
        }
        else{
            cnt++;
        }
    }
    return max(temp_max, cnt);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    for(int i = 1; i < 9; i++){
        for(int j = i + 1; j <= 9; j++){
            maxans = max(maxans, game(i, j));
        }
    }

    cout << maxans;
}
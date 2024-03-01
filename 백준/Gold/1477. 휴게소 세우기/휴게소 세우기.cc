#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int n, m, l;
vector<int> v;

bool solve(int ans){
    int cnt = 0;

    for(int i = 1; i < v.size(); i++){
        int dist = v[i] - v[i-1];
        cnt += dist / ans;
        if(dist % ans == 0){
            cnt--;
        }

    }

    if(cnt > m){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    cin >> n >> m >> l;
    v.push_back(0);
    v.push_back(l);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int left = 1;
    int right = l - 1;
    int maxans = 0;

    while(left <= right){
        int mid = (left + right) / 2;

        if(solve(mid)){
            left = mid + 1;
        }
        else{
            right = mid - 1;
            maxans = mid;
        }
    }

    cout << maxans;

}
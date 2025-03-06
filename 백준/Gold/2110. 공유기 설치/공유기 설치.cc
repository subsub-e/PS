#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, k;
vector<int> v;


bool func(int x){
    int cnt = 1;

    int start = v[0];

    for(int i = 1; i < v.size(); i++){
        if(v[i] >= x + start){
            start = v[i];
            cnt++;
        }
    }

    if(cnt < k){
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int left = 0;
    int right = v[v.size() - 1];
    int answer = -1;

    while(left <= right){
        int mid = (left + right) / 2;
        //cout << mid << '\n';
        if(func(mid)){
            left = mid + 1;
            answer = mid;
        }
        else{
            right = mid - 1;
        }
    }

    cout << answer;
    return 0;
}

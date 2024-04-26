#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int arr[16];
bool visited[16];
int n, l, r, x;
int cnt1;
vector<int> v;

void func(int now, int sum, int cnt){
    if(sum > r){
        return;
    }
    if(v.size() == cnt){
        //cout << sum << ' ' << arr[v[0]] << ' ' << arr[v[v.size() - 1]] << '\n';
        if(sum >= l && (arr[v[v.size() - 1]] - arr[v[0]]) >= x){
            cnt1++;
        }
        return;
        // for(int i = 0; i < v.size(); i++){
        //     cout << v[i] << ' ';
        // }
        // cout << '\n';
        // return;
    }

    for(int i = now; i < n; i++){
        if(!visited[i]){
            v.push_back(i);
            visited[i] = 1;
            func(i + 1, sum + arr[i], cnt);
            v.pop_back();
            visited[i] = 0;
        }
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n >> l >> r >> x;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for(int i = 2; i <= n; i++){
        func(0, 0, i);
    }

    cout << cnt1;
	
	return 0;
}
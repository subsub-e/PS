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

vector<int> v;
int n;
int maxans = 0;

void func(int sum){
    if(v.size() == 2){
        maxans = max(maxans, sum);
        return;
    }

    for(int i = 1; i < v.size() - 1; i++){
        int index = v[i];
        int temp = v[i-1] * v[i + 1];
        v.erase(v.begin() + i);
        func(sum + temp);
        v.insert(v.begin() + i, index);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    func(0);

    cout << maxans;

	return 0;
}
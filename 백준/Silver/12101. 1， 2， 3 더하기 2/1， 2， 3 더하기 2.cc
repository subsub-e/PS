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
#include <map>
using namespace std;

int n, k;
unordered_map<int, string> m;
vector<int> v;
int index1 = 1;

void func(int sum){
    if(sum > n){
        return;
    }
    if(sum == n){
        string str = "";
        for(int i = 0; i < v.size(); i++){
            str += (char) (v[i]);
        }
        m[index1] = str;
        index1++;
        return;
    }

    for(int i = 1; i <= 3; i++){
        v.push_back(i);
        func(sum + i);
        v.pop_back();
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n >> k;
    func(0);

    if(m.size() < k){
        cout << -1;
    }
    else{
        string temp = m[k];
        for(int i = 0; i < temp.length() - 1; i++){
            cout << (int) temp[i] << '+';
        }
        cout << (int) temp[temp.length() - 1];
    }
	
	return 0;
}
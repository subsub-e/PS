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

void func(int las){
    if(v.size() == las - 1){
        int sum = 1;
        int index = 2;
        for(int i = 0; i < v.size(); i++){
            if(v[i] == 0){
                if(i > 0 && v[i-1] == 0){
                    return;
                }
                if(i == 0){
                    sum = 12;
                    index = 3;
                    continue;
                }
                else{
                    if(v[i-1] == 1){
                        sum -= (index - 1);
                        sum += ((index - 1) * 10 + index);
                    }
                    else{
                        sum += (index - 1);
                        sum -= ((index - 1) * 10 + index);
                    }
                }
                index++;
                
            }
            else if(v[i] == 1){
                sum += index;
                index++;
            }
            else{
                sum -= index;
                index++;
            }
        }

        // for(int i = 0; i < v.size(); i++){
        //     cout << v[i] << ' ';
        // }
        // cout << sum << '\n';

        if(sum == 0){
            int index = 1;
            cout << index++;
            for(int i = 0; i < v.size(); i++){
                if(v[i] == 0){
                    cout << ' ';
                }
                else if(v[i] == 1){
                    cout << '+';
                }
                else{
                    cout << '-';
                }
                cout << index++;
            }
            cout << '\n';
        }

        return;
    }

    for(int i = 0; i < 3; i++){
        v.push_back(i);
        func(las);
        v.pop_back();
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
    while(t--){
        v.clear();
        int n; cin >> n;
        func(n);
        cout << '\n';
    }

	return 0;
}
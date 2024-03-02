#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
using namespace std;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int minans = INT_MAX;

    for(int i = 0; i < n-3; i++){
        for(int j = i + 3; j < n; j++){
            int snow = v[i] + v[j];
            int left = i + 1;
            int right = j - 1;

            while(left < right){
                minans = min(minans, abs(v[left] + v[right] - snow));
                //cout << i << ' ' << left << ' ' << right << ' ' << j << '\n';
                if(snow - (v[left] + v[right]) > 0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
    }
    cout << minans;
}
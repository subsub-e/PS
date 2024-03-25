#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int minans = INT_MAX;
    int left = 0;
    int right = v.size() - 1;
    int answer1, answer2;

    while(left < right){
        if(v[left] + v[right] == 0){
            cout << v[left] << ' ' << v[right] << '\n';
            return 0;
        }
        if(abs(v[left] + v[right]) < minans){
            answer1 = v[left];
            answer2 = v[right];
            minans = min(minans, abs(v[left] + v[right]));
        }
        if((v[left] + v[right]) < 0){
            left++;
        }
        else if((v[left] + v[right]) > 0){
            right--;
        }
    }

    cout << answer1 << ' ' << answer2;
}
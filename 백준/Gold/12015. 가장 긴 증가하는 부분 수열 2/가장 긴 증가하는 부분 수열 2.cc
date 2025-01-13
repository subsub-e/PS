#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    int ans = 0;
    vector<int> LIS;
    LIS.push_back(0);

    for(int i = 0; i < n; i++){
        if(LIS.back() < v[i]){
            LIS.push_back(v[i]);
        }
        else{
            int left = 0;
            int right = LIS.size();

            while(left < right){
                int mid = (int) (left + right) / 2;
                if(LIS[mid] < v[i]){
                    left = mid + 1;
                }
                else{
                    right = mid;
                }
            }
            LIS[right] = v[i];
        }
    }

    cout << (int) LIS.size() - 1;
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
using namespace std;

long long arr[3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    long long n; cin >> n;
    vector<long long> v;
    for(int i = 0; i < n; i++){
        long long x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    

    long long minans = 3000000001;

    for(int i = 0; i < n - 2; i++){
        int l = i + 1;
        int r = n - 1;
        while(l < r){
            long long sum = v[i] + v[l] + v[r];
            if(abs(sum) < minans){
                arr[0] = v[i];
                arr[1] = v[l];
                arr[2] = v[r];
                minans = abs(sum);
            }

            if(sum < 0){
                l++;
            }
            else{
                r--;
            }
        }
    }

    cout << arr[0] << ' ' << arr[1] << ' ' << arr[2];

	return 0;
}
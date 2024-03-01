#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
using namespace std;


int main(){
    long long t;
    cin >> t;
    int n; cin >> n;
    vector<int> A;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        A.push_back(x);
    }
    int m; cin >> m;
    vector<int> B;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        B.push_back(x);
    }

    vector<int> suma;
    vector<int> sumb;

    for(int i = 0; i < n; i++){
        int sum = A[i];
        suma.push_back(sum);
        for(int j = i + 1; j < n; j++){
            sum += A[j];
            suma.push_back(sum);
        }
    }
    for(int i = 0; i < m; i++){
        int sum = B[i];
        sumb.push_back(sum);
        for(int j = i + 1; j < m; j++){
            sum += B[j];
            sumb.push_back(sum);
        }
    }

    sort(suma.begin(), suma.end());
    sort(sumb.begin(), sumb.end());

    long long ans = 0;

    for(int i = 0; i < suma.size(); i++){
        int temp = t - suma[i];
        int upp = upper_bound(sumb.begin(), sumb.end(), temp) - sumb.begin();
        int low = lower_bound(sumb.begin(), sumb.end(), temp) - sumb.begin();
        ans += (upp - low);
    }
    cout << ans;
}
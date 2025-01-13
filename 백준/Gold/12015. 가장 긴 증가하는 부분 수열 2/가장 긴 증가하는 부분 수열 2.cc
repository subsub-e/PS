#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> LIS; // Longest Increasing Subsequence
    for (int i = 0; i < n; i++) {
        // LIS 배열에서 v[i]가 들어갈 위치를 찾음 (lower_bound 사용)
        auto pos = lower_bound(LIS.begin(), LIS.end(), v[i]);
        
        if (pos == LIS.end()) {
            // v[i]가 LIS의 가장 큰 값보다 크면 추가
            LIS.push_back(v[i]);
        } else {
            // 그렇지 않으면 기존 값을 대체
            *pos = v[i];
        }
    }

    cout << LIS.size() << endl; // LIS 배열의 크기가 최장 증가 부분 수열의 길이
    return 0;
}

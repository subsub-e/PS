#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        long long sum = 0;
        for(int i = 0; i < m; i++){
            int x; cin >> x;
            pq.push(x);
        }
        while(pq.size() > 1){
            long long x1 = pq.top();
            pq.pop();
            long long x2 = pq.top();
            pq.pop();
            sum += x1 + x2;
            pq.push(x1 + x2);
        }
        cout << sum << '\n';
    }
}
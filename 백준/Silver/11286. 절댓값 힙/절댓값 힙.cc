#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(void) {

	int n; cin >> n;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > pq;
    for(int i = 0; i < n; i++){
        long long x; cin >> x;
        if(x == 0){
            if(pq.empty()){
                cout << 0 << '\n';
            }
            else{
                long long temp = pq.top().first;
                int flag = pq.top().second;
                if(flag == 0){
                    cout << -temp << '\n';
                }
                else{
                    cout << temp << '\n';
                }
                pq.pop();
            }
        }
        else{
            if(x > 0){
                pq.push(make_pair(x, 1));
            }
            else{
                pq.push(make_pair(-x, 0));
            }
        }
    }
}
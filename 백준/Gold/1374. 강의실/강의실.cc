#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;



int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);

    int n; cin >> n;
    vector<pair<int, int> > v;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < n; i++){
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        v.push_back(make_pair(x2, x3));
    }

    sort(v.begin(), v.end());

    int cnt = 0;

    for(int i = 0; i < v.size(); i++){
        while(!pq.empty() && pq.top() <= v[i].first){
            //cout << pq.top() << ' ' <<  (int) pq.size() << '\n'; 
            pq.pop();
        }
        pq.push(v[i].second);
        cnt = max(cnt, (int) pq.size());
    }
    cout << cnt;
    return 0;
}
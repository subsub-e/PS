#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int> > v;
int n, ans;

bool comp(pair<int, int> v1, pair<int, int> v2){
    if(v1.first == v2.first){
        return v1.second > v2.second;
    }
    else{
        return v1.first < v2.first;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int cost, d;
        cin >> cost >> d;
        v.push_back(make_pair(d, cost));
    }

    sort(v.begin(), v.end(), comp);

    int day = 1;
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 0; i < n; i++){
        if(day > v[i].first){
            if(pq.top() < v[i].second){
                pq.push(v[i].second);
                ans -= pq.top();
                pq.pop();
                ans += v[i].second;
            }
        }
        else{
            pq.push(v[i].second);
            ans += v[i].second;
            day++;
        }
    }

    cout << ans;

}
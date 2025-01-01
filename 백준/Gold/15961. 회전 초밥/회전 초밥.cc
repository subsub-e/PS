#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int n, d, k, c;
vector<int> v;
int visited[3001];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> d >> k >> c;
    deque<int> dq;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    int maxans = 0;
    int s = 1;
    visited[c] = 10000;

    for(int i = 0; i < k; i++){
        if(visited[v[i]] == 0){
            s++;
        }
        visited[v[i]]++;
        dq.push_back(v[i]);
    }


    for(int i = k; i < n + k; i++){
        visited[dq[0]]--;
        if(visited[dq[0]] == 0){
            s--;
        }
        dq.pop_front();
        if(visited[v[i % n]] == 0){
            s++;
        }
        visited[v[i % n]]++;
        maxans = max(maxans, s);
        dq.push_back(v[i % n]);
    }

    cout << maxans;
    
}
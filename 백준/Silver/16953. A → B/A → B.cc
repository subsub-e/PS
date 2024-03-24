#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

long long n, m;
queue<pair<long long, long long> > q;

int func(){
    while(!q.empty()){
        long long x = q.front().first;
        //cout << x << '\n';
        long long cnt = q.front().second;
        if(x == m){
            return cnt;
        }
        q.pop();


        long long nx = x * 2;
        long long mx = x * 10 + 1;
        if(nx <= m){
            q.push(make_pair(nx, cnt + 1));
        }
        if(mx <= m){
            q.push(make_pair(mx, cnt + 1));
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    q.push(make_pair(n, 1));
    cout << func();
    return 0;
}
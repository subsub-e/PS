#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

vector<pair<int, int>> graph[100002];
int n, st, en;
int dist[100002];
bool visited[100002];
int max_dist[100002];

void dfs(int now)
{

    for (auto x : graph[now])
    {
        if (!visited[x.first])
        {
            visited[x.first] = 1;
            dist[x.first] = dist[now] + x.second;
            max_dist[x.first] = max(max_dist[now], x.second);
            dfs(x.first);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> st >> en;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, cost;
        cin >> x >> y >> cost;
        graph[x].push_back({y, cost});
        graph[y].push_back({x, cost});
    }

    visited[st] = 1;
    dfs(st);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dist[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << max_dist[i] << ' ';
    // }
    // cout << '\n';
    cout << dist[en] - max_dist[en];
}

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int n, w;
double m;
vector<pair<int, int>> v;
vector<pair<int, double>> line[1001];
double dist[1001];

double calculate(int x, int y)
{
    int x1 = v[x].first;
    int y1 = v[x].second;
    int x2 = v[y].first;
    int y2 = v[y].second;

    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void solution()
{
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty())
    {
        double cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        for (auto next : line[now])
        {
            int y = next.first;
            double next_cost = next.second;

            if (dist[y] > cost + next_cost)
            {
                dist[y] = cost + next_cost;
                pq.push({dist[y], y});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w >> m;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double cost = calculate(i, j);

            if (cost <= m)
            {
                line[i].push_back({j, cost});
                line[j].push_back({i, cost});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        dist[i] = 123456789.0;
    }

    for (int i = 0; i < w; i++)
    {
        int x, y;
        cin >> x >> y;
        line[x - 1].push_back({y - 1, 0});
        line[y - 1].push_back({x - 1, 0});
    }

    solution();

    cout << (int)(dist[n - 1] * 1000);
}

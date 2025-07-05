#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> v;
int uf[500001];
long long result;

int find(int x)
{
    if (uf[x] == x)
    {
        return x;
    }
    return uf[x] = find(uf[x]);
}

void Union(int x, int y)
{
    int X = find(x);
    int Y = find(y);

    if (X != Y)
    {
        uf[Y] = X;
    }
    else
    {
        uf[X] = Y;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long total = 0;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, cost;
        cin >> x >> y >> cost;
        v.push_back({cost, {x, y}});
        total += cost;
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= n; i++)
    {
        uf[i] = i;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (find(v[i].second.first) != find(v[i].second.second))
        {
            Union(v[i].second.first, v[i].second.second);
            result += v[i].first;
        }
    }

    int Parent = find(1);

    for (int i = 2; i <= n; i++)
    {
        if (find(i) != Parent)
        {
            cout << -1;
            return 0;
        }
    }

    cout << total - result;
}

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int t, n, m;
int indig[1002];
queue<int> q;
vector<int> v[1002];
pair<int, int> answer[1002];

void init()
{
    memset(indig, 0, sizeof(indig));
    for (int i = 0; i < 1001; i++)
    {
        v[i].clear();
    }
}

void simulate()
{
    int temp;
    cin >> temp >> n >> m;
    init();

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        indig[y]++;
        v[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
    {
        answer[i] = {-1, -1};
        if (indig[i] == 0)
        {
            answer[i] = {1, 1};
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int x = q.front();
        if (answer[x].second > 1)
        {
            answer[x].first++;
        }
        q.pop();

        for (auto now : v[x])
        {
            indig[now]--;
            if (answer[now].first == answer[x].first)
            {
                answer[now].second++;
            }
            else if (answer[now].first < answer[x].first)
            {
                answer[now] = {answer[x].first, 1};
            }

            if (indig[now] == 0)
            {
                q.push(now);
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << answer[i].first << ' ';
    // }
    // cout << '\n';

    cout << temp << ' ' << answer[n].first << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--)
    {
        simulate();
    }
}

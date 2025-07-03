#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int t, n, cnt;
int arr[100001];
bool visited[100001];
bool finish[100001];

void init()
{
    memset(visited, 0, sizeof(visited));
    memset(finish, 0, sizeof(finish));
    cnt = 0;
}

void dfs(int now)
{
    visited[now] = 1;
    int next = arr[now];

    if (!visited[next])
    {
        dfs(next);
    }
    else
    {
        if (!finish[next])
        {
            while (next != now)
            {
                cnt++;
                next = arr[next];
            }
            cnt++;
        }
    }
    finish[now] = 1;
}

void simulate()
{
    init();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x - 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    cout << n - cnt << '\n';
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
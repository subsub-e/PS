#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int t, n, m;
char arr[1001][1001];
bool visited[1001][1001];
bool visited_fire[1001][1001];
queue<pair<int, int>> q;
queue<pair<int, int>> fire;
int cnt[1001][1001];
int fire_cnt[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool cango(int x, int y)
{
    return 0 <= x && x < m && 0 <= y && y < n && arr[x][y] != '#';
}

void init()
{
    memset(visited, 0, sizeof(visited));
    memset(visited_fire, 0, sizeof(visited_fire));
    memset(cnt, -1, sizeof(cnt));
    memset(fire_cnt, -1, sizeof(fire_cnt));
}

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (cango(nx, ny) && !visited[nx][ny] && cnt[nx][ny] < cnt[x][y])
            {
                if ((fire_cnt[nx][ny] != -1 && cnt[x][y] + 1 < fire_cnt[nx][ny]) || fire_cnt[nx][ny] == -1)
                {
                    visited[nx][ny] = 1;
                    cnt[nx][ny] = cnt[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

void bfs_fire()
{
    while (!fire.empty())
    {
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (cango(nx, ny) && !visited_fire[nx][ny] && fire_cnt[nx][ny] < fire_cnt[x][y])
            {
                visited_fire[nx][ny] = 1;
                fire_cnt[nx][ny] = fire_cnt[x][y] + 1;
                fire.push({nx, ny});
            }
        }
    }
}

void answer()
{
    int maxans = 1e9;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
            {
                if (cnt[i][j] != -1)
                {
                    maxans = min(maxans, cnt[i][j]);
                }
            }
            // cout << cnt[i][j] << ' ';
        }
        // cout << '\n';
    }

    if (maxans != 1e9)
    {
        cout << maxans << '\n';
    }
    else
    {
        cout << "IMPOSSIBLE" << '\n';
    }
}

void simulate()
{
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '@')
            {
                q.push({i, j});
                visited[i][j] = 1;
                cnt[i][j] = 1;
            }
            if (arr[i][j] == '*')
            {
                fire.push({i, j});
                visited_fire[i][j] = 1;
                fire_cnt[i][j] = 1;
            }
        }
    }

    bfs_fire();
    bfs();
    answer();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--)
    {
        simulate();
    }
}
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
bool visited[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        visited[x][y] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        visited[i][i] = 1;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (visited[i][j] || (visited[i][k] && visited[k][j]))
                {
                    visited[i][j] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!(visited[i][j] || visited[j][i]))
            {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}

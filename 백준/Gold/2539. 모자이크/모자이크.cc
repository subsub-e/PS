#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int h, w, n, k;
vector<pair<int, int>> v;

bool simulate(int target)
{
    int cnt = 1;
    int left = v[0].first;

    for (int i = 1; i < k; i++)
    {
        if (v[i].second > target)
        {
            return false;
        }
        if (v[i].first > left + target - 1)
        {
            left = v[i].first;
            cnt++;
        }
    }

    if (cnt > n)
    {
        return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int y, x;
        cin >> y >> x;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    int st = 1;
    int en = min(h, w);
    int answer = -1;

    while (st <= en)
    {
        int mid = (st + en) / 2;

        if (simulate(mid))
        {
            en = mid - 1;
            answer = mid;
        }
        else
        {
            st = mid + 1;
        }
    }
    cout << answer;
}

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

queue<int> q[21];
vector<string> v;
int cnt[21];
int n, k;
long long answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }

    for (int i = 0; i < n; i++)
    {
        int len = v[i].length();

        while (!q[len].empty() && i - q[len].front() > k)
        {
            q[len].pop();
        }

        answer += q[len].size();
        q[len].push(i);
    }

    cout << answer;
}

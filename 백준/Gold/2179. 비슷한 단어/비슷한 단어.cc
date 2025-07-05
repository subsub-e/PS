#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> tab;
int n;
vector<string> v;

int max_size = 0;
int l, r;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] == v[j])
            {
                continue;
            }

            int len = min(v[i].size(), v[j].size());
            int temp = 0;

            for (int k = 0; k < len; k++)
            {
                if (v[i][k] == v[j][k])
                {
                    temp++;
                }
                else
                {
                    break;
                }
            }
            if (max_size < temp)
            {
                l = i;
                r = j;
                max_size = temp;
            }
        }
    }

    cout << v[l] << '\n'
         << v[r];
}

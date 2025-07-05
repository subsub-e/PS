#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int n, answer;
vector<int> men_minus;
vector<int> men_plus;
vector<int> women_minus;
vector<int> women_plus;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x < 0)
        {
            men_minus.push_back(x);
        }
        else
        {
            men_plus.push_back(x);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x < 0)
        {
            women_minus.push_back(x);
        }
        else
        {
            women_plus.push_back(x);
        }
    }

    sort(men_minus.begin(), men_minus.end());
    sort(men_plus.begin(), men_plus.end());
    sort(women_minus.begin(), women_minus.end());
    sort(women_plus.begin(), women_plus.end());

    int st = 0;
    int en = women_minus.size() - 1;

    while (st < men_plus.size() && en >= 0)
    {
        if (men_plus[st] < abs(women_minus[en]))
        {
            answer++;
            st++;
            en--;
        }
        else
        {
            en--;
        }
        // cout << st << ' ' << en << '\n';
    }

    st = 0;
    en = men_minus.size() - 1;

    while (st < women_plus.size() && en >= 0)
    {
        if (women_plus[st] < abs(men_minus[en]))
        {
            answer++;
            st++;
            en--;
        }
        else
        {
            en--;
        }
    }

    cout << answer;
}

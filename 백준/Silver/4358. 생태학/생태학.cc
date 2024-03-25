#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    map<string, double> m;
    double cnt = 0;
    string str;
    while(getline(cin, str)){
        cnt++;
        m[str]++;
    }
    cout << fixed;
    cout.precision(4);

    for (auto iter : m) {
		cout << iter.first << ' ' << (iter.second / cnt) * 100 << '\n';
	}

}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    unordered_map<string, string> m;
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        string str1, str2;
        cin >> str1 >> str2;
        m[str1] = str2;
    }

    for(int i = 0; i < k; i++){
        string str1;
        cin >> str1;
        cout << m[str1] << '\n';
    }
}
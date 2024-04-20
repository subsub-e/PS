#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <tuple>
#include <unordered_set>
using namespace std;

int arr[1001];

int main(int argc, char** argv)
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test_case;
    int T;
    

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        int maxans = -1;

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                string temp = to_string(arr[i] * arr[j]);
                int flag = 0;
                for(int k = 1; k < temp.length(); k++){
                    if(((int) temp[k-1] - '0' + 1) != ((int) temp[k] - '0')){
                        //cout << i << ' ' << j << ' ' << (int) temp[i-1] - '0' + 1 << '\n';
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    maxans = max(maxans, stoi(temp));
                }
            }
        }

        cout << '#' << test_case << ' ' << maxans << '\n';
    }
    return 0;
}
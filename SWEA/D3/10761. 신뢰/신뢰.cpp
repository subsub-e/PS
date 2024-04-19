#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <tuple>
using namespace std;


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
        pair<char, int> arr[n];
        for(int i = 0; i < n; i++){
            char c;
            int x;
            cin >> c >> x;
            arr[i] = make_pair(c, x);
        }

        int cnt = 0;
        int index1 = 1;
        int index2 = 1;
        int index3 = 0;
        int index4 = 0;
        for(int i = 0; i < n; i++){
            char now = arr[i].first;
            int dist = arr[i].second;
            if(now == 'B'){
                if(abs(dist - index1) - index4 < 0){
                    cnt++;
                    index3++;
                }
                else{
                    cnt += abs(dist - index1) - index4 + 1;
                    index3 += (abs(dist - index1) - index4 + 1);
                }
                //cout << cnt << '\n';
                
                index4 = 0;
                index1 = dist;
            }
            else{
                if(abs(dist - index2) - index3 < 0){
                    cnt++;
                    index4++;
                }
                else{
                    cnt += abs(dist - index2) - index3 + 1;
                    index4 += (abs(dist - index2) - index3 + 1);
                }   
                //cout << cnt << '\n';
                index3 = 0;
                index2 = dist;
            }
        }
        cout << '#' << test_case << ' ' << cnt << '\n';
    }
    return 0;
}
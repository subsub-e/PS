#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int r, c, k;
int arr[101][101];
int t = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
	cin >> r >> c >> k;
    r--;
    c--;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }

    int x = 3;
    int y = 3;

    while(t < 101){
        if(arr[r][c] == k){
            cout << t;
            return 0;
        }

        vector<int> Size;
        if(x > y){
            for(int i = 0; i < x; i++){
                int cnt[101] = {};
                vector<pair<int, int> > v;
                for(int j = 0; j < y; j++){
                    cnt[arr[j][i]]++;
                }
                for(int j = 1; j <= 100; j++){
                    if(cnt[j] != 0){
                        v.push_back(make_pair(cnt[j], j));
                    }
                }
                sort(v.begin(), v.end());
                for(int j = 0; j < y; j++){
                    arr[j][i] = 0;
                }
                int index = 0;
                for(int j = 0; j < v.size(); j++){
                    arr[index++][i] = v[j].second;
                    arr[index++][i] = v[j].first;
                }
                Size.push_back(index);
            }
            sort(Size.begin(), Size.end());
            y = Size.back();
        }
        else{
            for(int i = 0; i < y; i++){
                int cnt[101] = {};
                vector<pair<int, int> > v;
                for(int j = 0; j < x; j++){
                    cnt[arr[i][j]]++;
                }
                for(int j = 1; j <= 100; j++){
                    if(cnt[j] != 0){
                        v.push_back(make_pair(cnt[j], j));
                    }
                }
                sort(v.begin(), v.end());
                for(int j = 0; j < x; j++){
                    arr[i][j] = 0;
                }
                int index = 0;
                for(int j = 0; j < v.size(); j++){
                    arr[i][index++] = v[j].second;
                    arr[i][index++] = v[j].first;
                }
                Size.push_back(index);
            }
            sort(Size.begin(), Size.end());
            x = Size.back();
        }
        t++;
        // cout << t << '\n';
        // for(int i = 0; i < y; i++){
        //     for(int j = 0; j < x; j++){
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    cout << -1;
	return 0;
}
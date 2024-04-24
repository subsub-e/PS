#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
#include <queue>

using namespace std;

int n;
char arr[7][7];
vector<pair<int, int> > v;
vector<pair<int, int> > comb;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool Inrange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool game(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 'T'){
                for(int k = 0; k < 4; k++){

                    int nx = i;
                    int ny = j;

                    for(int p = 0; p <= 6; p++){
                        nx += dx[k];
                        ny += dy[k];

                        if(!Inrange(nx, ny) || arr[nx][ny] == 'O'){
                            break;
                        }
                        if(arr[nx][ny] == 'S'){
                            return false;
                        }
                    }
                    
                }
            }
        }
    }
    cout << "YES";
    exit(0);
}

void func(int now){
    if(comb.size() == 3){
        // for(int i = 0; i < 3; i++){
        //     cout << comb[i].first << ' ' << comb[i].second << '\n';
        // }
        for(int i = 0; i < 3; i++){
            int x = comb[i].first;
            int y = comb[i].second;
            arr[x][y] = 'O';
        }
        game();
        for(int i = 0; i < 3; i++){
            int x = comb[i].first;
            int y = comb[i].second;
            arr[x][y] = 'X';
        }
        return;
        
    }

    for(int i = now; i < v.size(); i++){
        comb.push_back(make_pair(v[i].first, v[i].second));
        func(i + 1);
        comb.pop_back();
    }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'X'){
                v.push_back(make_pair(i, j));
            }
        }
    }

    func(0);

    cout << "NO";
	return 0;
}
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

int arr[51][51];
int base[51][51];
int n, m, t;
int maxans = INT_MAX;
int temp[51][51];
int v[7][4];
bool visited[7];
vector<int> comb;

void func(int x1, int y1, int x2, int y2){
    int temp_x1 = x1;
    int temp_x2 = x2;
    int temp_y1 = y1;
    int temp_y2 = y2;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            temp[i][j] = arr[i][j];
        }
    }

    while(temp_x1 < temp_x2 && temp_y1 < temp_y2){

        for(int i = temp_x2; i > temp_x1; i--){
            temp[i-1][temp_y1] = arr[i][temp_y1];
        }

        for(int i = temp_y2; i > temp_y1; i--){
            temp[temp_x1][i] = arr[temp_x1][i-1];
        }

        for(int i = temp_x2; i > temp_x1; i--){
            temp[i][temp_y2] = arr[i-1][temp_y2];
        }

        for(int i = temp_y2; i > temp_y1; i--){
            temp[temp_x2][i-1] = arr[temp_x2][i];
        }

        temp_x1++;
        temp_x2--;
        temp_y1++;
        temp_y2--;
    }

    for(int i = x1; i <= x2; i++){
        for(int j = y1; j <= y2; j++){
            arr[i][j] = temp[i][j];
        }
    }

    return;
}

void com(int now, int size){
    if(comb.size() == size){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                arr[i][j] = base[i][j];
            }
        }
        for(int i = 0; i < size; i++){
            func(v[comb[i]][0], v[comb[i]][1], v[comb[i]][2], v[comb[i]][3]);
        }
        // for(int i = 0; i < size; i++){
        //     cout << comb[i] << ' ';
        // }

        int minans = INT_MAX;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < m; j++){
                sum += arr[i][j];
            }
            minans = min(minans, sum);
        }

        maxans = min(maxans, minans);
        //cout << maxans << '\n';

        return;
    }

    for(int i = 0; i < size; i++){
        if(!visited[i]){
            visited[i] = 1;
            comb.push_back(i);
            com(now + 1, size);
            visited[i] = 0;
            comb.pop_back();
        }
    }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> t;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            base[i][j] = arr[i][j];
        }
    }

    int index = 0;
    while(t--){
        int x, y, z; cin >> x >> y >> z;
        int x1 = x - z - 1;
        int y1 = y - z - 1;
        int x2 = x + z - 1;
        int y2 = y + z - 1;
        v[index][0] = x1;
        v[index][1] = y1;
        v[index][2] = x2;
        v[index][3] = y2;
        index++;
    }

    com(0, index);

    cout << maxans;

	return 0;
}
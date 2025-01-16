#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, maxans;

vector<vector<int> > up(vector<vector<int> > temp){
    queue<int> q;
    for(int j = 0; j < n; j++){
        int i = 0;
        int k = 1;
        while(k < n){
            if(temp[i][j] == temp[k][j]){
                if(temp[i][j] != 0){
                    q.push(temp[i][j] + temp[k][j]);
                }
                i = k + 1;
                k += 2;
            }
            else{
                if(temp[k][j] == 0){
                    k++;
                }
                else if(temp[i][j] == 0){
                    i++;
                    k++;
                }
                else{
                    q.push(temp[i][j]);
                    k++;
                    i = k - 1;
                }
            }
        }
        if(i < n && temp[i][j] != 0){
            q.push(temp[i][j]);
        }
        i = 0;
        while(!q.empty()){
            temp[i][j] = q.front();
            q.pop();
            i++;
        }

        while (i < n) {
            temp[i][j] = 0;
            i++;
        }
    }

    return temp;
}

vector<vector<int> > down(vector<vector<int> > temp){
    queue<int> q;
    for(int j = 0; j < n; j++){
        int i = n - 1;
        int k = n - 2;
        while(k >= 0){
            if(temp[i][j] == temp[k][j]){
                if(temp[i][j] != 0){
                    q.push(temp[i][j] + temp[k][j]);
                }
                i = k - 1;
                k -= 2;
            }
            else{
                if(temp[k][j] == 0){
                    k--;
                }
                else if(temp[i][j] == 0){
                    i--;
                    k--;
                }
                else{
                    q.push(temp[i][j]);
                    k--;
                    i = k + 1;
                }
            }
        }
        if(i >= 0 && temp[i][j] != 0){
            q.push(temp[i][j]);
        }
        i = n - 1;
        while(!q.empty()){
            temp[i][j] = q.front();
            q.pop();
            i--;
        }

        while (i >= 0) {
            temp[i][j] = 0;
            i--;
        }
    }

    return temp;
}

vector<vector<int> > left(vector<vector<int> > temp){
    queue<int> q;
    for(int i = 0; i < n; i++){
        int j = 0;
        int k = 1;
        while(k < n){
            if(temp[i][j] == temp[i][k]){
                if(temp[i][j] != 0){
                    q.push(temp[i][j] + temp[i][k]);
                }
                j = k + 1;
                k += 2;
            }
            else{
                if(temp[i][k] == 0){
                    k++;
                }
                else if(temp[i][j] == 0){
                    j++;
                    k++;
                }
                else{
                    q.push(temp[i][j]);
                    k++;
                    j = k - 1;
                }
            }
        }
        if(j < n && temp[i][j] != 0){
            q.push(temp[i][j]);
        }
        j = 0;
        while(!q.empty()){
            temp[i][j] = q.front();
            q.pop();
            j++;
        }

        while (j < n) {
            temp[i][j] = 0;
            j++;
        }
    }

    return temp;
}

vector<vector<int> > right(vector<vector<int> > temp){
    queue<int> q;
    for(int i = 0; i < n; i++){
        int j = n-1;
        int k = n-2;
        while(k >= 0){
            if(temp[i][j] == temp[i][k]){
                if(temp[i][j] != 0){
                    q.push(temp[i][j] + temp[i][k]);
                }
                j = k - 1;
                k -= 2;
            }
            else{
                if(temp[i][k] == 0){
                    k--;
                }
                else if(temp[i][j] == 0){
                    j--;
                    k--;
                }
                else{
                    q.push(temp[i][j]);
                    k--;
                    j = k + 1;
                }
            }
        }
        if(j >= 0 && temp[i][j] != 0){
            q.push(temp[i][j]);
        }
        j = n - 1;
        while(!q.empty()){
            temp[i][j] = q.front();
            q.pop();
            j--;
        }

        while (j >= 0) {
            temp[i][j] = 0;
            j--;
        }
    }

    return temp;
}

void dfs(vector<vector<int>> temp, int cnt) {
    if (cnt == 5) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxans = max(maxans, temp[i][j]);
            }
        }
        return;
    }

    // for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < n; j++) {
    //             cout << temp[i][j] << ' ';
    //         }
    //         cout << '\n';
    //     }
    // cout << '\n';

    vector<vector<int> > up_v = up(temp);
    dfs(up_v, cnt + 1);


    vector<vector<int> > down_v = down(temp);
    dfs(down_v, cnt + 1);

    vector<vector<int> > left_v = left(temp);
    dfs(left_v, cnt + 1);

    vector<vector<int> > right_v = right(temp);
    dfs(right_v, cnt + 1);

}

int main() {
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(arr, 0);

    cout << maxans << '\n';
    return 0;
}

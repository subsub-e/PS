#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

int n;
char arr[51][51];
int maxans;

void func(){
    int sum = 1;
    for(int i = 0; i < n; i++){
        char temp = arr[i][0];
        for(int j = 1; j < n; j++){
            if(temp == arr[i][j]){
                sum++;
            }
            else{
                maxans = max(maxans, sum);
                sum = 1;
                temp = arr[i][j];
            }
        }
        maxans = max(maxans, sum);
        sum = 1;
    }

    sum = 1;
    for(int i = 0; i < n; i++){
        char temp = arr[0][i];
        for(int j = 1; j < n; j++){
            if(temp == arr[j][i]){
                sum++;
            }
            else{
                maxans = max(maxans, sum);
                sum = 1;
                temp = arr[j][i];
            }
        }
        maxans = max(maxans, sum);
        sum = 1;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[i][j] != arr[i][j + 1]){
                char temp = arr[i][j];
                char temp1 = arr[i][j + 1];
                arr[i][j] = temp1;
                arr[i][j + 1] = temp;
                func();
                arr[i][j + 1] = temp1;
                arr[i][j] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[j][i] != arr[j + 1][i]){
                char temp = arr[j][i];
                char temp1 = arr[j + 1][i];
                arr[j][i] = temp1;
                arr[j + 1][i] = temp;
                func();
                arr[j + 1][i] = temp1;
                arr[j][i] = temp;
            }
        }
    }

    cout << maxans;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int arr[26][200001];
int sum[26][200001];

int func(char c){
    return (int) c - 97;
}

int main(){
    string str;
    int n;
    cin >> str >> n;

    for(int i = 0; i < str.length(); i++){
        arr[func(str[i])][i]++;
    }

    for(int i = 0; i < 26; i++){
        sum[i][0] = arr[i][0];
        for(int j = 1; j < str.length(); j++){
            sum[i][j] = arr[i][j] + sum[i][j - 1];
        }
    }

    while(n--){
        char c;
        int start, end;
        cin >> c >> start >> end;
        cout << sum[func(c)][end] - sum[func(c)][start - 1] << '\n';
    }
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n;
int cnt = 0;
bool visited[40];
bool visited1[40];
bool visited2[40];

void func(int x){
    if(x == n){
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i] && !visited1[i + x] && !visited2[x - i + n - 1]){
            visited[i] = 1;
            visited1[i + x] = 1;
            visited2[x - i + n - 1] = 1;
            func(x + 1);
            visited[i] = 0;
            visited1[i + x] = 0;
            visited2[x - i + n - 1] = 0;
        }
    }
}

int main()
{
    cin >> n;
    func(0);
    cout << cnt;
    return 0;
}
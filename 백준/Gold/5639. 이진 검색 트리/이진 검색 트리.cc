#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

void dfs(int start, int end){
    if(start >= end){
        return;
    }
    // if(start == end - 1){
    //     cout << v[start] << '\n';
    //     return;
    // }
    int index = start + 1;
    while(index < end){
        if(v[start] < v[index]){
            break;
        }
        index++;
    }
    dfs(start + 1, index);
    dfs(index, end);
    cout << v[start] << '\n';
}

int main(){
    int value;
    while(cin >> value){
        v.push_back(value);
    }

    dfs(0, v.size());
}
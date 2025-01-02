#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int visited[27];

int main(){
    int x; cin >> x;
    string str; cin >> str;
    int maxans = 0;
    int st = 0;
    int en = 0;
    int cnt = 0;
    

    while(en < str.length()){
        //cout << st << ' ' << en << '\n';
        int index_en = (char) str[en] - 97;
        if(visited[index_en] == 0){
            while(cnt >= x && st < en){
                int index_st = (char) str[st] - 97;
                visited[index_st]--;
                if(visited[index_st] == 0){
                    cnt--;
                }
                st++;
            }
            cnt++;
        }
        visited[index_en]++;
        en++;
        maxans = max(maxans, en-st);
    }
    cout << maxans;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 1000000
int N;
string startStr,endStr;
int Cal(bool same, int check){
    int count = 0;
    vector<int> cnt;
    vector<int> fin;

    for(int i = 0; i < startStr.length(); i++) {
        cnt.push_back(startStr[i]-'0');
        fin.push_back(endStr[i]-'0');
    }
    if(same){
        count = check;
        cnt[2] = (check == 2)? ((cnt[2] == 1)? 0 : 1) : cnt[2];
    }
    else{
        count = 1;
        cnt[0] = (cnt[0] == 1) ? 0 : 1;
        cnt[1] = (cnt[1] == 1) ? 0 : 1;
        if(check == 3) cnt[2] = (cnt[2] == 1) ? 0 : 1;
    }
    for(int i = 1; i < cnt.size(); i++){
      if(cnt[i] != fin[i] && i+1 < N) {
        count++;
        for(int j = 0; j <=2; j++) 
            if(i+j < N) cnt[i+j]= (cnt[i+j] == 1) ? 0 : 1;
        }
    }
    for(int i = 1; i < cnt.size(); i++) if(cnt[i] != fin[i]) return MAX;
    return count;
}
int Solution(){
    int val = MAX;
    if(startStr == endStr) return 0;
    if(startStr[0] == endStr[0]){
        val = min(Cal(true,0),Cal(true,2));
    }
    else val= min(Cal(false,1),Cal(false,3));

    return val;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    cin >> startStr >> endStr;

    int val = Solution();
    int ans = (val >= MAX) ? -1 : val;
    cout << ans;

}
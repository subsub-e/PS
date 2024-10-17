#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxans = 0;
    int minans = 0;
    for(int i = 0; i < sizes.size(); i++){
        if(sizes[i][0] > sizes[i][1]){
            maxans = max(maxans, sizes[i][0]);
            minans = max(minans, sizes[i][1]);
        }
        else{
            maxans = max(maxans, sizes[i][1]);
            minans = max(minans, sizes[i][0]);
        }
    }
    return maxans * minans;
}
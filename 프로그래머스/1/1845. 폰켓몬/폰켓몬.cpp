#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<int> s;

int solution(vector<int> nums)
{
    int answer = 0;
    int cnt = 1;
    for(int i = 0; i < nums.size(); i++){
        if(i == 0){
            s.insert(nums[i]);
            continue;
        }
        if(cnt == nums.size() / 2){
            break;
        }
        if(s.find(nums[i]) == s.end()){
            s.insert(nums[i]);
            cnt++;
        }
    }
    answer = cnt;
    return answer;
}
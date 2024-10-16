#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> s;
    for(int i = 0; i < nums.size(); i++){
        s.insert(nums[i]);
    }
    
    if(s.size() > nums.size()/2){
        return nums.size()/2;
    }
    return s.size();
}
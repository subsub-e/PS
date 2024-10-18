#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int left = 0;
    int right = people.size()-1;
    sort(people.begin(), people.end());
    while(left < right){
        if(people[left] + people[right] <= limit){
            // cout << left << ' ' << right << '\n';
            answer++;
            left++;
        }
        right--;
    }
    return people.size() - answer;
}
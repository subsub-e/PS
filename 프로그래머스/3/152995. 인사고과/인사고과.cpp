#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> scores)
{
    int answer = scores.size()+1, wanho=scores[0][0] + scores[0][1], size = scores.size();
    for(auto c : scores)// 완호의 인센티브 자격 확인
        if (scores[0][0] < c[0] && scores[0][1] < c[1]) return -1;
    sort(scores.begin()+1, scores.end());//완호 점수를 제외하고 오름차순 정렬
    for(int i=1;i<size;i++)
    {
        if (wanho >= scores[i][0] + scores[i][1]) continue;//최적화를 위해 완호점수가 해당 도합점수보다 크다면 넘긴다.
        for(int j=i+1;j<size;j++)
        {
            if(scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1])
            {//도합점수는 완호보다 크지만 인센티브를 못받는 경우
                answer--;//등수 올려줌
                break;
            }
        }
    }
    for(auto c : scores) if (wanho >= c[0] + c[1]) answer--;//완호가 점수 더 크거나 같다면 등수 올려줌
    return answer;
}
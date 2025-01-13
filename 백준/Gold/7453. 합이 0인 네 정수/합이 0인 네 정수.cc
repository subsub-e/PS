#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> v1;
vector<long long> v2;
vector<long long> v3;
vector<long long> v4;
vector<long long> sum_v1;
vector<long long> sum_v2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        long long x1, x2, x3, x4;
        cin >> x1 >> x2 >> x3 >> x4;
        v1.push_back(x1);
        v2.push_back(x2);
        v3.push_back(x3);
        v4.push_back(x4);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            long long sum = v1[i] + v2[j];
            sum_v1.push_back(sum);
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            long long sum = v3[i] + v4[j];
            sum_v2.push_back(sum);
        }
    }

    sort(sum_v1.begin(), sum_v1.end());
    sort(sum_v2.begin(), sum_v2.end());


    long long ans = 0;

    long long left = 0;
    long long right = sum_v2.size() - 1;

    while(left < sum_v1.size() && right >= 0){
        if(sum_v1[left] + sum_v2[right] == 0){
            long long temp = left;
            long long sumA = 0;
            long long sumB = 0;
            while(sum_v1[left] + sum_v2[right] == 0){
                left++;
                sumA++;
                if(left >= sum_v1.size()){
                    break;
                }
            }
            while(sum_v1[temp] + sum_v2[right] == 0){
                
                right--;
                sumB++;
                if(right < 0){
                    break;
                }
                
            }
            ans += (sumA * sumB);
        }
        else if(sum_v1[left] + sum_v2[right] < 0){
            left++;
        }
        else{
            right--;
        }
    }

    cout << ans;
}


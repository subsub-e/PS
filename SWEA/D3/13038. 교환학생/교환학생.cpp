#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
 


int main(int argc, char** argv)
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_case;
    int T;
     
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n; cin >> n;
        int arr[7];
        for(int i = 0; i < 7; i++){
            cin >> arr[i];
        }

        
        int minans = INT_MAX;

        for(int i = 0; i < 7; i++){
            int sum = 0;
            int ans = 0;
            int index = 0;
            int temp = arr[0];
            for(int j = 1; j < 7; j++){
                arr[j-1] = arr[j];
            }
            arr[6] = temp;

            while(sum < n){
                if(arr[index % 7] == 1){
                    sum++;
                }
                index++;
                ans++;
            }
            minans = min(minans, ans);
            
        }


        cout << '#' << test_case << ' ' << minans << '\n';




    }
    return 0;
}
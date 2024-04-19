#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
 
int check[10];

int main(int argc, char** argv)
{
    int test_case;
    int T;
     
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string str; cin >> str;
        memset(check, 0, sizeof(check));
        int len = str.length();
        vector<int> v1;
        for(int i = 0; i < len; i++){
            int x = (int)str[i] - 48;
            check[(int)str[i] - 48]++;
            v1.push_back(x);
        }

        int v2[len];
        for(int i = 0; i < len; i++){
            for(int j = 0; j < 10; j++){
                if(check[j] > 0){
                    if(i == 0 && j == 0){
                        continue;
                    }
                    v2[i] = j;
                    check[j]--;
                    break;
                }
            }
        }
        sort(v1.rbegin(), v1.rend());

        // for(int i = 0; i < len; i++){
        //     cout << v2[i] << ' ';
        // }
        // cout << '\n';
	
        int maxans = 0;
        int minans = INT_MAX;

        for(int i = 0; i < len; i++){
            string temp = str;
        
            if((int)temp[i] - 48 != v1[i]){
                //cout << i << '\n';
                for(int j = 0; j < len; j++){
                    if(v1[i] == (int) temp[j] - 48){
                        string temp3 = temp;
                        //cout << j << '\n';
                        char c = temp[i];
                        temp[i] = temp[j];
                        temp[j] = c;
                        maxans = max(maxans, stoi(temp));
                        temp = temp3;
                    }
                }
            }
        }


        for(int i = 0; i < len; i++){
            string temp2 = str;
            if((int)temp2[i] - 48 != v2[i]){
                for(int j = 0; j < len; j++){
                    if(v2[i] == (int) temp2[j] - 48){
                        string temp3 = temp2;
                        char c = temp2[i];
                        temp2[i] = temp2[j];
                        temp2[j] = c;
                        if(temp2[0] == '0'){
                            temp2 = temp3;
                            continue;
                        }
                        minans = min(minans, stoi(temp2));
                        temp2 = temp3;
                    }
                }
            }
        }

        cout << '#' << test_case << ' ' << min(minans, stoi(str)) << ' ' << max(maxans, stoi(str)) << '\n';

    }
    return 0;
}
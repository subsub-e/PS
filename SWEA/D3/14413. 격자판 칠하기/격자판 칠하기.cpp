#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
     
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
 
        int n, m;
        cin >> n >> m;
        char arr[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> arr[i][j];
            }
        }

        int flag = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == '?'){
                    continue;
                }
                char temp = arr[i][j];
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(0 <= nx && nx < n && 0 <= ny && ny < m){
                        if(arr[nx][ny] == '?'){
                            if(temp == '#'){
                                arr[nx][ny] = '.';
                            }
                            else{
                                arr[nx][ny] = '#';
                            }
                            continue;
                        }
                        if((temp == '#' && arr[nx][ny] == '#') || (temp == '.' && arr[nx][ny] == '.')){
                            flag = 1;
                        }
                    }
                }
            }
        }

        if(flag == 1){
            cout << '#' << test_case << ' ' << "impossible" << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << "possible" << '\n';
        }


    }
    return 0;
}
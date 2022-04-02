/**
 * @file 9625.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 9625 BABBA / 구현
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int s[50][2];

    for(int i=0; i<=N; i++){
        s[i][0] = 0;
        s[i][1] = 0;
    }

    s[0][0] = 1;
    s[1][1] = 1;

    for(int i=2; i<=N; i++){
        s[i][0] = s[i-1][0] + s[i-2][0];
        s[i][1] = s[i-1][1] + s[i-2][1];
    }

    cout << s[N][0] << ' ' << s[N][1];
}
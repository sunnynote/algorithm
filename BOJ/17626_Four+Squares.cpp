/**
 * @file 17626.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 17626 Four Squares
 * @version 0.1
 * @date 2022-03-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int d[50005];

void solve(){
    d[1] = 1;

    for(int i=2; i<=N; i++){
        d[i] = d[1] + d[i-1];

        for(int j=2; j*j<=i; j++){
            d[i] = min(d[i], 1 + d[i-j*j]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    solve();
    cout << d[N];

    return 0;
}
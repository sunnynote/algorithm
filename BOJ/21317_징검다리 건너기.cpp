/**
 * @file 21317.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 21317 징검다리 건너기 / DFS
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

int N, K, ans = 987654321;
int arr[25][2];

void input(){
    cin >> N;

    for(int i=1; i<N; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    cin >> K;
}

void solve(int cur, int energy, bool f){
    if(cur > N) return;
    
    if(cur == N){
        if(ans > energy) ans = energy;
        return;
    }

    solve(cur+1, energy + arr[cur][0], f);
    solve(cur+2, energy + arr[cur][1], f);
    if(!f) solve(cur+3, energy + K, true);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve(1, 0, 0);

    cout << ans << '\n';

    return 0;
}
/**
 * 200701
 * BOJ 2916 자와 각도기
 * DP
 * */
#include <iostream>
#include <vector>
using namespace std;
int N, K;
int angle[12], want[12];
int dp[362][12];
int res[362];

void solve(int cur, int idx){ // 현재 각, 위치
    if(idx==N || dp[cur][idx]) return;

    dp[cur][idx] = true;
    res[cur] = true;

    int ncur = (cur + angle[idx] + 360) % 360;
    if(!dp[ncur][idx])
        solve(ncur, idx);
    
    ncur = (cur - angle[idx] + 360) % 360;
    if(!dp[ncur][idx])
        solve(ncur, idx);

    solve(cur, idx+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++)
        cin >> angle[i];
    for(int i=0; i<K; i++)
        cin >> want[i];

    solve(0, 0);

    for(int i=0; i<K; i++){
        if(res[want[i]]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

/**
 * 200522
 * BOJ 2616 소형기관차
 * DP !!
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N, MX;
int train[50005];
int tie[50005]; 
int dp[4][50005];

int ans = -1;

void solve(){
    // 한 열차가 운송 할 수 있는 손님 수
    for(int i=1; i<=N; i++){
        for(int j=i; j<=i+MX-1; j++){
            if(j>N) break;
            tie[i] += train[j];
        }
    }

    // base
    dp[1][1] = tie[1];
    for(int i=2; i<=N; i++)
        dp[1][i] = max(dp[1][i-1], tie[i]);

    // 2
    for(int i=MX+1 ; i<=N; i++)
        for(int j=1; j<=i-MX; j++)
            dp[2][i] = max(dp[2][i-1], dp[1][j]+tie[i]);
    // 3
    for(int i=MX*2+1 ; i<=N; i++)
        for(int j=1; j<=i-MX; j++)
            dp[3][i] = max(dp[3][i-1], dp[2][j]+tie[i]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> train[i];
    cin >> MX;
    
    solve();
    cout << dp[3][N];

    return 0;
}
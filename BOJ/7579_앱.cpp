/**
 * 21-03-15
 * BOJ 7579 앱
 * DP - knapsack
 * */

#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M;
int cur[101];
int cost[101];
int dp[101][10001]; // [k][x] : k까지 사용, cost=x 일 때 메모리 값

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        cin >> cur[i];
    
    for(int i=1; i<=N; i++)
        cin >> cost[i];

    int ans = INF;

    dp[0][cost[0]] = cur[0]; // base
    
    for(int k=1; k<=N; k++){
        for(int x=0; x<=10000; x++){
            if(x-cost[k] >= 0)
                dp[k][x] = max(dp[k][x], dp[k-1][x-cost[k]]+cur[k]);
            dp[k][x] = max(dp[k][x], dp[k-1][x]);

            if(dp[k][x] >= M) ans = min(ans, x);
        }
    }

    cout << ans << '\n';

    return 0;
}
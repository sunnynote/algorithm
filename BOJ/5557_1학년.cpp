/**
 * 200601
 * BOJ 5557 1학년
 * DP
 * */

#include <iostream>
using namespace std;

int N;
int num[105];
long long dp[105][22]; // i까지 사용해서 j만드는 방법

void solve(){
    dp[1][num[1]]++;

    for(int i=2; i<N; i++){
        for(int j=0; j<=20; j++){
            if(dp[i-1][j]!=0){
                if(j-num[i] >= 0)
                    dp[i][j-num[i]] += dp[i-1][j];
                if(j+num[i] <= 20)
                    dp[i][j+num[i]] += dp[i-1][j];
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> num[i];
    
    solve();
    cout << dp[N-1][num[N]];
    return 0;
}

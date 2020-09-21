/**
 * 200921
 * BOJ 2625
 * 동전 바꿔주기
 * DP
 * */

#include <iostream>
using namespace std;

int T, K;
pair<int,int> arr[1001];
int d[10001][101]; 
// [N원][동전 K개 사용]
// N원을 만드는 경우의수 -- K번째 동전까지 사용

void solve(){
    for(int i=1; i<=K; i++){
        d[0][i-1] = 1;

        for(int j=1; j<=arr[i].second; j++){
            for(int k=arr[i].first*j; k<=T; k++){
                d[k][i] += d[k-(arr[i].first*j)][i-1];
            }
        }

        for(int j=1; j<=T; j++)
            d[j][i] += d[j][i-1];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T >> K;
    for(int i=1; i<=K; i++)
        cin >> arr[i].first >> arr[i].second;
    
    solve();

    cout << d[T][K];
    return 0;
}
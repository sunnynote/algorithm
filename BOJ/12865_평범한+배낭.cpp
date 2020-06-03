/**
 * 200602
 * BOJ 12865 평범한 배낭
 * DP -- knapsack
 * */


#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
pair<int,int> arr[105];
int d[105][100005];

void solve(){
    d[0][0]=0;

    for(int i=1; i<=N; i++){ // 물건
        int weight = arr[i].first;
        int val = arr[i].second;

        for(int j=0; j<=K; j++){ // 배낭의 무게
            if(j >= weight)
                d[i][j] = max(d[i-1][j-weight] + val, d[i-1][j]);
            else 
                d[i][j] = d[i-1][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    for(int i=1; i<=N; i++)
        cin >> arr[i].first >> arr[i].second;

    solve();

    cout << d[N][K];

    return 0;
}

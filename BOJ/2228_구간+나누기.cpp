/**
 * 200708
 * BOJ 2228 구간 나누기
 * DP
 * d[n][m] : 1~n의 인덱스까지 중 m개의 구간을 선택함
 * */

#include <iostream>
#include <algorithm>
#include <cstring>
#define MN -987654321
using namespace std;

int N, M;
int arr[104];
int sum[104]; // 누적 합

int d[104][52];

int solve(int cur, int cnt){
    if(cnt==0) return 0;
    if(cur<=0) return MN;

    int &ret = d[cur][cnt];
    if(ret!=-1) return ret;

    ret = solve(cur-1, cnt);
    for(int i=1; i<=cur; i++)
        ret = max(ret, solve(i-2, cnt-1)+sum[cur]-sum[i-1]);

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        cin >> arr[i];

    for(int i=1; i<=N; i++)
        sum[i] = sum[i-1] + arr[i];
    
    memset(d, -1, sizeof(d));
    cout << solve(N, M);
    return 0;
}
/**
 *  200518 BOJ 1727 커플 만들기
 *  DP + sort 
 *  DP는 어려워요
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int m[1005];
int f[1005];
int d[1005][1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++)
        cin >> m[i];
    for(int i=1; i<=M; i++)
        cin >> f[i];

    sort(m+1, m+N+1);
    sort(f+1, f+M+1);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            d[i][j] = d[i-1][j-1] + abs(m[i] - f[j]);

            if(i>j) d[i][j] = min(d[i][j], d[i-1][j]); // 남자가 많음 
            if(i<j) d[i][j] = min(d[i][j], d[i][j-1]); // 여자가 많음
        }
    }

    cout << d[N][M];
    
    return 0;
}
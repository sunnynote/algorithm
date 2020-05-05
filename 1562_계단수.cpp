/**
 * 200505
 * BOJ 1562 계단수
 * DP + 비트마스킹
 * 
 * */

#include <iostream>
#define mod 1000000000
using namespace std;

int d[101][10][1<<10];
int main(){
    int N;
    cin >> N;

    // base : 1자리 계단수
    for(int i=1; i<=9; i++)
        d[1][i][1<<i] = 1;

    int check = (1<<10) - 1;
    for(int i=2; i<=N; i++){ // N 자릿수까지 계산
        for(int j=0; j<=9; j++){ // 마지막 자리 숫자
            for(int k=0; k<=check; k++){ // 사용했는지 확인하는 상태비트
                if(j==0)
                    d[i][0][k | (1<<0)]
                        = (d[i][0][k | (1<<0)] + d[i-1][1][k]) % mod;
                else if(j==9)
                    d[i][9][k | (1<<9)]
                        = (d[i][9][k | (1<<9)] + d[i-1][8][k]) % mod;
                
                else{
                    d[i][j][k | (1<<j)]
                        = (d[i][j][k | (1<<j)] + d[i-1][j-1][k]) % mod;
                    d[i][j][k | (1<<j)]
                        = (d[i][j][k | (1<<j)] + d[i-1][j+1][k]) % mod;
                }
            }
        }
    }

    int ans = 0;
    for(int j=0; j<=9; j++)
        ans = (ans + d[N][j][check]) % mod;
    cout << ans;    
    return 0;
}
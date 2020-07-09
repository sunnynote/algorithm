/**
 * 200709
 * BOJ 2560 짚신벌레
 * DP
 * */

#include <iostream>
using namespace std;

int d[10004];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, D, N;
    d[0]=1;
    cin >> A >> B >> D >> N;

    // d[i] = d[i-1] + d[i-A] - d[i-B]
    // i일 태어난 벌레 수 = i-1일 태어난 벌레 수 + 성체O노화X - 성체O노화O
    for(int i=1; i<=N; i++){
        if(i<A) 
            d[i] = d[i-1] % 1000;
        else if(i<B)
            d[i] = (d[i-1] + d[i-A]) % 1000;
        else
            d[i] = (d[i-1] + d[i-A] - d[i-B] + 1000) % 1000;
    }

    // N일 존재 벌레 수 = N일까지 태어난 벌레 수 - 죽은 벌레수
    if(N-D >= 0) // 죽는 것이 가능하면
        cout << (d[N] - d[N-D] + 1000) % 1000;
    else
        cout << d[N] % 1000;

    return 0;
}
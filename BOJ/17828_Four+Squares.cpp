/**
 * 21-04-19
 * BOJ 17626 Four Squares
 * DP
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int d[50005];

void solve(){
    //init
    for(int i=1; i<=N; i++)
        d[i] = 4;
    
    for(int i=1; i<=230; i++)
        d[i*i] = 1;

    for(int i=2; i<=N; i++)
        for(int j=2; j*j<=i; j++)
            d[i] = min(d[i], d[j*j] + d[i-j*j]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    solve();
    cout << d[N];

    return 0;
}
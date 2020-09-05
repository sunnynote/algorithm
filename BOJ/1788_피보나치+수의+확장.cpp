/**
 * 200905
 * BOJ 1788 피보나치 수의 확장
 * DFS (or DP..)
 * */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
long long f[1000005];

long long solve(int n){
    long long &ret = f[n];
    if(ret!=-1) return ret;
    ret = solve(n-1) + solve(n-2);
    return ret%1000000000;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int inputN = abs(N);

    memset(f, -1, sizeof(f));
    f[0]=0; f[1]=1;
    long long val = solve(inputN);

    if(N==0) cout << 0 << '\n' << val;
    else if(N%2==0 && N<0) cout << -1 << '\n' << abs(val);
    else cout << 1 << '\n' << val;

    return 0;
}

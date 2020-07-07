/**
 * 200705
 * BOJ 2747 피보나치 수
 * */

#include <iostream>
using namespace std;

int d[46];

int fibo(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(d[n]!=0) return d[n];

    return d[n]=fibo(n-1)+fibo(n-2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;

    cout << fibo(N);
    return 0;
}
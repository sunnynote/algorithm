/**
 * 200613
 * BOJ 1669
 * 멍멍이 쓰다듬기
 * */

#include <iostream>
using namespace std;

long long summ(long long n){
    return n*(n+1)/2;
}

// 현재 횟수 주어졌을때, 가능한 최대 이동거리
long long func(int cur){
    long long d = 0;
    if(cur<=2) return cur;

    if(cur%2==0)
        d = summ(cur/2) * 2;
    else
        d = summ((cur-1)/2) * 2 + ((cur-1)/2)+1;
    
    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long X, Y;
    cin >> X >> Y;

    long long diff = Y - X;
    long long ans = 1; // 현재 횟수
    
    if(diff==0){
        cout << 0;
        return 0;
    }

    while(diff > func(ans))
        ans++;
    
    cout << ans;
    return 0;
}

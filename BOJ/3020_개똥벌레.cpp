/**
 * 200516 BOJ 3020 개똥벌레
 * 
 * */

#include <iostream>
using namespace std;

int N,H;
int s[500005]; // 석순
int j[500005]; // 종유석
int a[500005];
int mn;

void solution(){
    a[1] = mn = N/2;

    // 구간 1~H 탐색
    // 다음 구간 = 이전 구간 - 석순 + 종유석
    for(int i=2; i<=H; i++){
        a[i] = a[i-1] - s[i-1] + j[H-i+1];
        mn = min(mn, a[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> H;
    for(int i=1; i<=N; i++){
        int x;
        cin >> x;
        if(i%2==1) s[x]++;
        else j[x]++;
    }
    solution();

    int cnt=0;
    for(int i=1; i<=H; i++)
        if(mn==a[i]) cnt++;

    cout << mn << ' ' << cnt;
    return 0;
}
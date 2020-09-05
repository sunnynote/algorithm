/**
 * 200905
 * BOJ 2212 센서
 * greedy
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int loc[10005];
int diff[10005];

bool cmp(int a, int b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=1; i<=N; i++)
        cin >> loc[i];
    
    sort(loc+1, loc+1+N);

    for(int i=2; i<=N; i++)
        diff[i] = loc[i] - loc[i-1];

    sort(diff+2, diff+2+N, cmp);
    
    //del
    for(int i=2; i<=K; i++)
        diff[i]=0;

    int ans=0;
    for(int i=2; i<=N; i++)
        ans += diff[i];
    
    cout << ans;
    return 0;
}
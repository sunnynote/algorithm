/**
 * 21-10-05
 * BOJ 1758 알바생 강호
 * 정렬
 * */

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int N;
int arr[100001];

bool cmp(int a, int b){
    if(a > b) return true;
    return false;
}

void solve(){
    sort(arr+1, arr+N+1, cmp);

    ll ans = 0;
    for(int i=1; i<=N; i++){
        int val = arr[i] - (i-1);
        if(val > 0) ans += val;
    }

    cout << ans << '\n';
}

void input(){
    cin >> N;

    for(int i=1; i<=N; i++)
        cin >> arr[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
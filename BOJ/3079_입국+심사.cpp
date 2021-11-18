/**
 * 21-11-18
 * BOJ 3079 입국심사
 * */
#include <iostream>
#define ll long long
using namespace std;

int N, M;
ll arr[100002];
ll mx_time = -1;
ll ans;

void solve(){
    ll left = 0;
    ll right = mx_time * M;

    while(left<=right){
        ll mid = (left+right) / 2;
        ll sum = 0;

        for(int i=0; i<N; i++){
            sum += mid/arr[i];
        }

        if(sum < M){
            left = mid + 1;
        }
        else {
            ans = mid;
            right = mid - 1;
        }
    }

    cout << ans;
}

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        if(mx_time < arr[i]) mx_time = arr[i]; 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
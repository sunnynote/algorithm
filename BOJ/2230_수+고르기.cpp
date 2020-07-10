/**
 * 200711
 * BOJ 2230 수 고르기
 * two pointer
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100002];

int solve(){
    int ans=2e9;
    int s=1, e=1;

    while(s<=N && e<=N){
        int diff = arr[e]-arr[s];

        if(diff>=M){
            s++;
            ans = min(ans, diff);
        }
        else e++;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++)
        cin >> arr[i];
    sort(arr+1, arr+1+N);

    cout << solve();
    return 0;
}
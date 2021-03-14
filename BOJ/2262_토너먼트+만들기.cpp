/**
 * 21-03-14
 * BOJ 2262 토너먼트 만들기
 * 그리디
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[258];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i=1; i<=N; i++)
        cin >> arr[i];

    int ans = 0;
    for(int i=N; i>1; i--){ // N-1회 반복

        int idx;
        for(int j=1; j<=N; j++){ // 가장 큰 수 찾기
            if(i==arr[j]){
                idx = j;
                break;
            }
        }

        // 인접한 것 찾아 비교하여 차이 최소 구하기
        if(idx==1){
            ans += arr[idx] - arr[idx+1];
        }
        else if(idx==i){
            ans += arr[idx] - arr[idx-1];
        } 
        else {
            ans += arr[idx] - max(arr[idx-1], arr[idx+1]);
        }

        // 한칸씩 당기기
        for(int j=idx; j<i; j++){
            arr[j] = arr[j+1];
        }
    }

    cout << ans;

    return 0;
}
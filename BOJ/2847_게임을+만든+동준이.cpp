/**
 * 21-03-11
 * BOJ 2847 게임을 만든 동준이
 * 그리디
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int arr[102];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;

    for(int i=1; i<=N; i++)
        cin >> arr[i];

    int ans = 0;
    int val = arr[N];
    for(int i=N-1; i>0; i--){
        if(arr[i] >= val){
            ans += (arr[i]-val + 1);
            val -= 1;
        }
        else{
            val = arr[i];
        }
    }


    cout << ans << '\n';
    return 0;
} 
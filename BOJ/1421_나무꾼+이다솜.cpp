/**
 * @file 1421.cpp
 * @author sunny
 * @brief BOJ 1421 나무꾼 이다솜 - 구현
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <algorithm>
using namespace std;

int N, C, W;
int arr[52];

void solve(){
    sort(arr, arr+N+1);

    long long sum;
    long long mx = -1;

    for(int i=1; i<=arr[N]; i++){
        sum = 0;

        for(int j=1; j<=N; j++){
            if(arr[j] >= i){
                int cost = 0;
                if(arr[j]%i==0) cost = -1;
                
                if((arr[j]/i)*i*W > (arr[j]/i+cost)*C)
                    sum += (arr[j]/i)*i*W - (arr[j]/i+cost)*C;
            }
        }

        if(mx < sum) mx = sum;
    }

    cout << mx << '\n';
}

void input(){
    cin >> N >> C >> W;
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
/**
 * @file 14719.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 14719 빗물 / 구현
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

int N, M, mx, ans = 0;
int arr[501], resA[501], resB[501];

int main(){
    cin >> N >> M;

    for(int i=0; i<M; i++){
        cin >> arr[i];
    }

    mx = arr[0];
    for(int i=0; i<M; i++){
        if(mx < arr[i]) mx = arr[i];
        resA[i] = mx;
    }

    mx = arr[M-1];
    for(int i=M-1; i>=0; i--){
        if(mx < arr[i]) mx = arr[i];

        if(resA[i] <= mx) resB[i] = resA[i];
        else resB[i] = mx;
    }

    for(int i=0; i<M; i++){
        ans += (resB[i] - arr[i]);
    }
    cout << ans << '\n';

    return 0;
}
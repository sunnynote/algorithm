/**
 * @file 24620.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

int T, N;
int arr[100005];

bool func(int target){
    int sum = 0;

    for(int i=0; i<N; i++){
        sum += arr[i];
        
        if(sum > target) return false;
        sum %= target;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--){
        cin >> N;

        int sum = 0;
        for(int i=0; i<N; i++){
            cin >> arr[i];
            sum += arr[i];
        }

        int ans = 0;
        for(int i=1; i<=sum; i++){
            // sum의 약수이면서, 모든 수가 i(target)로 같아질 수 있다면
            if(sum % i == 0 && func(i)){
                ans = N - sum / i;
                break;
            }
        }

        cout << ans << '\n';
    }
}
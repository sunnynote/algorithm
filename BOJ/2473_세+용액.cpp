/**
 * 20-10-01
 * BOJ 2473 세 용액
 * 이분 탐색.. + 자료형(long long)
 * */

#include <iostream>
#include <algorithm>
#define MAX 3000000001
using namespace std;

int N;
long long arr[5001];
long long ans[3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> arr[i];

    sort(arr, arr+N);

    long long res = MAX;

    for(int idx=0; idx<N-2; idx++){
        int left = idx+1;
        int right = N-1;

        while(left<right){
            long long sum = arr[idx] + arr[left] + arr[right];

            if(res > abs(sum)){
                res = abs(sum);
                ans[0] = arr[idx];
                ans[1] = arr[left];
                ans[2] = arr[right];
            }

            if(sum==0) break;
            else if(sum<0) left++;
            else right--;
        }
    }
    
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
    return 0;
}

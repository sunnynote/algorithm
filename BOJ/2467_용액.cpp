/**
 * 21-10-01
 * BOJ 2467 용액
 * 투 포인터
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100001];
int left_idx, right_idx;

void solve(){

    int left = left_idx = 0;
    int right = right_idx = N-1;
    int sum = arr[left] + arr[right];
    int res = abs(sum);

    while(left < right){
        int tmp_sum = arr[left] + arr[right];
        
        if(res > abs(tmp_sum)) {
            res = abs(tmp_sum);
            left_idx = left;
            right_idx = right;
        }

        if(tmp_sum < 0) left++;
        else right--;
    }
}

void input(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> arr[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    cout << arr[left_idx] << ' ' << arr[right_idx];

    return 0;
}
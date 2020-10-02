/**
 * 201001
 * BOJ 2470
 * 두 용액
 * 이분 탐색
 * */

#include <iostream>
#include <algorithm>
#define MAX 2100000001
using namespace std;

int N;
int arr[100005];
int ans[2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> arr[i];
    
    sort(arr, arr+N);

    int left=0, right=N-1; // idx
    int res=MAX;

    while(left < right){
        int sum = arr[left] + arr[right];

        if(res > abs(sum)){ // update
            res = abs(sum);
            ans[0] = arr[left];
            ans[1] = arr[right];
        }

        if(sum==0) break;
        else if(sum>0) right--;
        else left++;
    }

    cout << ans[0] << ' ' << ans[1];

    return 0;
}


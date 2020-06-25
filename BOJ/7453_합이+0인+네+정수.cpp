/**
 * 200625
 * BOJ 7453
 * binary search -- upper / lower
 */
#include <iostream>
using namespace std;

int N;
int arr[4005][4];
int val1[4005];
int val2[4005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N;j++){
            val1[N*i+j] = -(arr[i][0] + arr[j][1]);
            val2[N*i+j] = arr[i][2] + arr[j][3]; 
        }
    }

    sort(val2, val2+N); // for binary search

    int left = 0;
    int right = N*N;
    long long ans = 0;

    for(int i=0; i<N*N; i++){
        while(left<right){
            int mid = (left+right)/2;

            if(val1[i] > val2[mid])
                left = mid + 1;
            else
                right = mid;
        }
        
        
        // lower_bound와 upper_bound의 차이 만큼 중복으로 존재
        int low = right;
        // int low2 = lower_bound(val2, val2+N*N, val1[i]) - val2;
        left = 0, right = N*N;
        
        while (left < right) {
            int mid = (left + right) / 2;

            if (val1[i] >= val2[mid])
                left = mid + 1;
            else
                right = mid;
        }

        int upper = right;
        // int upper2 = upper_bound(val2, val2+N*N, val1[i]) - val2;

        ans += (long long)(upper - low);
        left = 0, right = N*N;
    }

    cout << ans;
    return 0;
}
/**
 *  201001
 * BOJ 2559 수열
 * */

#include <iostream>
#define MAX -987654321
using namespace std;

int N, K;
int arr[100005];
int sum[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    for(int i=0; i<N; i++)
        cin >> arr[i];

    int res = 0;
    for(int i=0; i<N; i++){
        if(i<K-1) {
            res += arr[i];
            sum[i] = res;
            continue;
        }

        res += ( arr[i] - arr[i-K] );
        sum[i] = res; 
    }

    int ans = MAX;
    for(int i=K-1; i<N; i++)
        if(ans < sum[i]) ans = sum[i];

    cout << ans << '\n';
    return 0;
}
/**
 * 201001
 * BOJ 2470
 * 두 용액
 * */

#include <iostream>
#include <algorithm>
#define MAX 2100000001
using namespace std;

int N;
int arr[100005];
long long ans[2];

bool cmp(long long a, long long b){
    if(abs(a)<abs(b)) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> arr[i];
    
    sort(arr, arr+N, cmp);

    long long res=MAX;
    for(int i=0; i<N-1; i++){
        if( res > abs(arr[i] + arr[i+1]) ){
            ans[0] = arr[i];
            ans[1] = arr[i+1];
            res = abs(arr[i]+arr[i+1]);
        }
    }

    if(ans[0]<ans[1]) cout << ans[0] << ' ' << ans[1];
    else cout << ans[1] << ' ' << ans[0];

    return 0;
}
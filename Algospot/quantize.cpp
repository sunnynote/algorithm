/**
 * 21-01-14
 * 동적계획법
 * */

#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, S;
int arr[102];
int sum[102];
int bigsum[102];
int cache[102][12];

void sumCalc(){
    sort(arr, arr+N);
    sum[0] = arr[0];
    bigsum[0] = arr[0] * arr[0];

    for(int i=1; i<N; i++){
        sum[i] = sum[i-1] + arr[i];
        bigsum[i] = bigsum[i-1] + arr[i]*arr[i];
    }
}

int minError(int left, int right){
    int res1 = sum[right] - (left==0? 0 : sum[left-1]);
    int res2 = bigsum[right] - (left==0? 0 : bigsum[left-1]);
    int mid = int(0.5 + (double)res1 / (right-left+1));

    int ret = res2 - 2*mid*res1 + mid*mid*(right-left+1);

    return ret;
}

int solve(int loc, int cnt){
    if(loc==N) return 0;
    if(cnt==0) return INF;

    int &ret = cache[loc][cnt];
    if(ret != -1) return ret;

    ret = INF;
    for(int i=1; i+loc<=N; i++){
        ret = min(ret, minError(loc, loc+i-1) + solve(loc+i, cnt-1));
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        memset(cache, -1, sizeof(cache));
        cin >> N >> S;
        for(int i=0; i<N; i++)
            cin >> arr[i];

        sumCalc();
        cout << solve(0, S) << '\n';
    }
    
    return 0;
}
/**
 * 20-10-23
 * BOJ 2805 나무 자르기
 * 이분 탐색
 * */

#include <iostream>
#include <algorithm>
using namespace std;

long long N, M;
long long arrHeight[1000005];

long long solve(long long cur){
    long long res = 0;
    for(int i=0; i<N; i++)
        if(arrHeight[i]>cur)
            res += (arrHeight[i]-cur);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++)
        cin >> arrHeight[i];

    sort(arrHeight, arrHeight+N);

    long long left = 1, right = arrHeight[N-1];
    
    while(left<=right){
        long long mid = (left+right)/2;

        if(solve(mid) < M)
            right = mid - 1;
        else
            left = mid + 1;
    }
    
    cout << right << '\n';
    return 0;
}

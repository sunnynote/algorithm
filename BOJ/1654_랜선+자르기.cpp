/**
 * 20-10-23
 * BOJ 1654 랜선 자르기
 * 이분 탐색
 * */

#include <iostream>
#include <algorithm>
using namespace std;

long long K, N;
long long arrLine[10005];

long long lineCnt(long long cur){
    long long cnt = 0;
    for(int i=0; i<K; i++)
        cnt += (arrLine[i]/cur);
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> K >> N;

    for(int i=0; i<K; i++)
        cin >> arrLine[i];

    sort(arrLine, arrLine+K);
    
    // Binary Search
    long long left = 1;
    long long right = arrLine[K-1];
    while(left<=right){
        long long mid = (left+right)/2;

        if(lineCnt(mid)<N)
            right = mid - 1;
        else
            left = mid + 1;
    }

    cout << right << '\n';
    return 0;
}
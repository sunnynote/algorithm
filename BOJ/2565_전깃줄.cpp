/**
 * 200522
 * BOJ 2565 전깃줄
 * LIS 최장 증가 부분 수열
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int,int> arr[105];
int mxLen[105];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr, arr+N);

    // LIS (Longest Increasing Subsequence)
    for(int i=0; i<N; i++){
        mxLen[i] = 1;

        for(int j=0; j<i; j++){
            if(arr[j].second < arr[i].second){
                mxLen[i] = max(mxLen[j]+1, mxLen[i]);
            }
        }
    }

    int ans = -1;
    for(int i=0; i<N; i++)
        ans = max(ans, mxLen[i]);

    // LIS에 포함되지 않는 것 갯수 출력
    cout << N-ans << '\n';

    return 0;
}

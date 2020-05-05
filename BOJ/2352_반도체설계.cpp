/**
 * BOJ 2352 반도체 설계
 * LIS 
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int a[40005];
int LIS[40005];

int main(){
    int N;
    cin >> N;

    for(int i=1; i<=N; i++)
        cin >> a[i];

    // fill(d, d+N, 1);
    // int ans = -1;
    // for(int i=0; i<N; i++){

    //     for(int j=0; j<i; j++)
    //         if(a[i] > a[j])
    //             d[i] = max(d[i], d[j]+1);

    //     ans = max(ans, d[i]);
    // }
    int idx = 1;

    LIS[1]=a[1];

    for(int i=2; i<=N; i++){

        // 꼬이지 않으면 다음 순서로
        if(LIS[idx] < a[i]){
            idx++;
            LIS[idx] = a[i];
            continue;
        }

        // i번째 왼쪽에 연결되어있는 오른쪽의 번호보다 작지 않은 최초의 위치 찾기
        int tmp = lower_bound(LIS+1, LIS+1+idx, a[i]) - LIS; //first, lat, value
        LIS[tmp] = a[i];
    }

    cout << idx;

    return 0;
}

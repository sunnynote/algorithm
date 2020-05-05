/*
BOJ 1477 휴게소 세우기
분류 : 이분탐색
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, L;
int a[205];
int ans=0;

bool func(int x){ // 간격이 x이하일 때, 필요한 휴게소 M개 이하인지
    int cnt=0;
    for(int i=0; i<=N; i++){
        if(a[i+1] - a[i] > x){ // 간격이 넘으면 휴게소 세운다
            cnt += (a[i+1]-a[i]-1)/x;
        }
    }
    if(cnt > M) return true;
    return false;
}

int main(){
    cin >> N >> M >> L;
    for(int i=1; i<=N; i++)
        cin >> a[i];
    a[0]=0;
    a[N+1]=L;
    sort(a, a+N+2);

    int left = 1;
    int right = 1001;
    while(left<=right){
        int mid = (left+right)/2;

        if(func(mid)) left = mid+1;
        else right = mid-1;
    }
    cout << left;
    return 0;
}
/**
 * 21-03-09
 * BOJ 1911 흙길 보수하기
 * 그리디, 스위핑
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
struct Info{
    int start, end;
};
Info arr[10005];

bool cmp(Info &i1, Info &i2){
    if(i1.start == i2.start) return i1.end < i2.end;
    return i1.start < i2.start;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> L;
    
    for(int i=0; i<N; i++)
        cin >> arr[i].start >> arr[i].end;
    
    sort(arr, arr+N, cmp);

    int ans = 0;
    int loc = 0;

    for(int i=0; i<N; i++){
        int x = arr[i].start;
        int y = arr[i].end;
        if(x < loc) x = loc;
        if(x > y) continue;

        int diff = y - x;
        int cnt = diff/L;
        if( diff%L != 0) cnt++;

        ans += cnt;
        loc = x + L*cnt;
    }

    cout << ans << '\n';
    return 0;
}
/**
 * 200708
 * BOJ 4811 알약
 * DP
 * */

#include <iostream>
#include <cstring>
using namespace std;

int N;
long long d[31][31];

long long solve(int full, int half){
    if(full==0 && half==0) return 1;

    long long &ret=d[full][half];
    if(ret!=0) return ret;

    // case 1 -- 반 쪼개서 먹고, 병에 넣기
    if(full>0)
        ret += solve(full-1, half+1);
    // case 2 -- 반 조각 꺼내기
    if(half>0)
        ret += solve(full, half-1);
    
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(1){
        cin >> N;
        if(N==0) break;

        memset(d, 0, sizeof(d));
        cout << solve(N,0) << '\n';
    }

    return 0;
}

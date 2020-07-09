/**
 * 200709
 * BOJ 1563 개근상
 * DP
 * */

#include <iostream>
#include <cstring>
using namespace std;

int N;
int d[1004][3][4];

int solve(int day, int L, int A){
    if(L>=2 || A>=3) return 0;
    if(day==N) return 1;

    int &ret=d[day][L][A];
    if(ret!=-1) return ret;

    //출석, 지각, 결석
    d[day][L][A] = 0;
    d[day][L][A] += solve(day+1, L, 0);
    d[day][L][A] += solve(day+1, L+1, 0);
    d[day][L][A] += solve(day+1, L, A+1);

    d[day][L][A] %= 1000000;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    memset(d, -1, sizeof(d));
    cout << solve(0, 0, 0);
    return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, A, B, LEN;
int a[22];
int d[22][22][22]; // [열린문1][열린문2][현재 위치]

int solution(int open1, int open2, int idx){
    if(idx==LEN) return 0;
    if(d[open1][open2][idx] != -1) return d[open1][open2][idx];

    // d[][][] = min( 열린문1의 이동, 열린문2의 이동 )
    d[open1][open2][idx] = min( solution(a[idx], open2, idx+1) + abs(a[idx]-open1), 
                                    solution(open1, a[idx], idx+1) + abs(a[idx]-open2));
    return d[open1][open2][idx];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    cin >> A >> B;
    cin >> LEN;
    for(int i=0; i<LEN; i++)
        cin >> a[i];

    memset(d, -1, sizeof(d));
    cout << solution(A, B, 0) << '\n';

    return 0;
}
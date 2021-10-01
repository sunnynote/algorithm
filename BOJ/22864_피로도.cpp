/**
 * 21-10-01
 * BOJ 22864 피로도
 * 수학
 * */
#include <iostream>
using namespace std;

int A, B, C, M;
int ans;

void solve(){
    int cur_stress = 0;
    for(int t=1; t<=24; t++){
        if(cur_stress + A <= M){
            cur_stress += A;
            ans += B;
        }
        else cur_stress -= C;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> A >> B >> C >> M;

    if(A<=M) solve();

    cout << ans << '\n';

    return 0;
}
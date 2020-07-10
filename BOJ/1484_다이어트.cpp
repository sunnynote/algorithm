/**
 * 200711
 * BOJ 1484 다이어트
 *  two pointer
 * */

#include <iostream>
using namespace std;

int G;
bool flag=false;

void solve(){
    int ans = 0, cur = 0;
    int s=1, e=1;

    while( !(e-s == 1 && e*e-s*s>G) ){
        if(e*e - s*s >= G) s++;
        else e++;

        if(e*e - s*s == G){
            flag = true;
            cout << e << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> G;

    solve();
    if(!flag) cout << -1;
    return 0;
}

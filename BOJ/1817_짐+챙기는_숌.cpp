/**
 * 21-11-16
 * BOJ 1817 짐 챙기는 숌
 * 그리디
 * */

#include <iostream>
using namespace std;

int N, M;
int sum = 0, ans = 0;
int x;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> x;

        sum += x;
        if(sum==M){
            sum = 0;
            ans++;
        }
        else if(sum>M){
            sum = x;
            ans++;
        }
    }

    if(sum!=0) ans++;

    cout << ans << '\n';
    return 0;
}
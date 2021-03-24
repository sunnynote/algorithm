/**
 * 21-03-16
 * 컵홀더
 * 구현 / 그리디
 * */

#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;

    string s;
    cin >> s;
    
    int ans = 1;
    for(int i=0; i<N; i++){
        ans += 1;
        if(s[i]=='L') i++;
    }

    if(ans > N) ans = N;

    cout << ans << '\n';
    return 0;
}
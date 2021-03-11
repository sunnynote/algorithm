/**
 * 21-03-11
 * BOJ 4796 캠핑
 * */

#include <iostream>
using namespace std;

int main(){
    int cnt = 0;
    
    while(1){
        int L, P, V;
        cin >> L >> P >> V;
        if(L==0 && P==0 && V==0) break;

        int ans = L * (V/P);
        ans += V%P>L ? L : (V%P);

        cout << "Case " << ++cnt << " : " << ans << '\n';
    }

    return 0;
}
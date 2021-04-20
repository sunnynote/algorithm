/**
 * 21-04-06
 * BOJ 1759 암호 만들기
 * 백트래킹
 */

#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char arr[16];
bool chk[16];

void solve(int cnt, int idx){
    if(cnt==L){
        int resA = 0, resB = 0;
        for(int i=0; i<C; i++){
            if(chk[i]){
                if(arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u') resA++;
                else resB++;
            }
        }
        if(resA>=1 && resB>=2){
            for(int i=0; i<C; i++)
                if(chk[i]) cout << arr[i];
            cout <<'\n';
        }
        return;
    }

    for(int i=idx; i<C; i++){
        if(chk[i]) continue;

        chk[i] = true;
        solve(cnt+1, i);
        chk[i] = false;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> L >> C;
    for(int i=0; i<C; i++)
        cin >> arr[i];
    
    sort(arr, arr+C);
    solve(0, 0);

    return 0;
}
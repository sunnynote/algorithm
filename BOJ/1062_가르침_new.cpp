/**
 * 21-03-16
 * 가르침
 * DFS
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
string s[50];
bool chk[27]; // 알파벳배열 a~z기록
int ans;

int avail(){
    int res = 0;

    for(int i=0; i<N; i++){
        bool f = true;

        for(int j=4; j<s[i].length() - 4; j++){
            char cur = s[i][j]; //'a' 'b'
            if(!chk[cur-'a']){
                f = false;
                break;
            }
        }
        if(f) res++;
    }

    return res;
}

void solve(int idx, int cnt){
    if(cnt==K){
        ans = max(avail(), ans);
        return;
    }

    for(int i=idx; i<26; i++){
        if(chk[i]) continue;

        chk[i] = true;
        solve(i, cnt+1);
        chk[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> s[i];
    }

    if(K==26) ans = N;
    else if(K>=5) {
        K -= 5;
        chk['a'-'a'] = true;
        chk['n'-'a'] = true;
        chk['t'-'a'] = true;
        chk['i'-'a'] = true;
        chk['c'-'a'] = true;
        solve(0, 0);
    }
    else ans = 0;

    cout << ans << '\n';
    
    return 0;
}
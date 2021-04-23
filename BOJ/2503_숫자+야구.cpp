/**
 * 21-04-19
 * BOJ 2503 숫자 야구
 * Brute Force
 */

#include <iostream>
#include <cstring>
using namespace std;

bool chk[1000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    memset(chk, true, sizeof(chk));

    for(int i=123; i<=999; i++){ // init
        int tmp = i;
        int c = tmp%10; tmp/=10;
        int b = tmp%10; tmp/=10;
        int a = tmp%10;

        if(a==b || b==c || a==c) chk[i] = false;
        if(a==0 || b==0 || c==0) chk[i] = false;
    }

    for(int i=1; i<=N; i++){
        int input, num, S, B;
        cin >> input >> S >> B;

        for(int j=123; j<=999; j++){
            if(!chk[j]) continue;

            string inp = to_string(input);
            string cmp = to_string(j);

            int sCnt=0, bCnt=0;
            for(int a=0; a<3; a++)
                for(int b=0; b<3; b++){
                    if(a==b && inp[a]==cmp[b]) sCnt++;
                    if(a!=b && inp[a]==cmp[b]) bCnt++;
                }

            if(S!=sCnt || B!=bCnt) chk[j] = false;
        }
    }

    int ans = 0;
    for(int i=123; i<=999; i++)
        if(chk[i]) ans++;
    
    cout << ans << '\n';

    return 0;
}
/**
 * 21-10-05
 * BOJ 1455 뒤집기2
 * 그리디
 * */

#include <iostream>
using namespace std;

int N, M;
int map[101][101];
int ans = 0;

bool is_complete(){
    bool f = true;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(map[i][j]==1) f = false;
        }
        if(!f) break;
    }

    if(f) return true;
    return false;
}

void func(int x, int y){
    ans++;

    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            if(map[i][j]==0) map[i][j] = 1;
            else map[i][j] = 0;
        }
    }    
}

void solve(){
    while(!is_complete()){
        for(int i=N; i>=1; i--)
            for(int j=M; j>=1; j--)
                if(map[i][j]==1)
                    func(i, j);
    }

    cout << ans;
}

void input(){
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        string s;
        cin >> s;

        for(int j=1; j<=M; j++)
            map[i][j] = s[j-1] - '0';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
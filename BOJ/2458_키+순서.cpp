/**
 * 21-10-08
 * BOJ 2458 키 순서
 * DFS
 * */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector <int> high[501];
vector <int> low[501];

bool chk[501];
int ans = 0;

void dfs(int x, vector <int> v[]){
    for(int i=0; i<v[x].size(); i++){
        int nx = v[x][i];

        if(!chk[nx]) {
            dfs(nx, v);
            chk[nx] = true;
        }
    }
}

void solve(){
    for(int i=1; i<=N; i++){
        memset(chk, false, sizeof(chk));

        dfs(i, high);
        dfs(i, low);

        int cnt = 0;
        for(int j=1; j<=N; j++)
            if(chk[j]) cnt++;

        if(cnt==N-1) ans++;
    }

    cout << ans << '\n';
}

void input(){
    cin >> N >> M;

    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        high[a].push_back(b);
        low[b].push_back(a);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
/**
 * 21-10-08
 * BOJ 13023 ABCDE
 * DFS
 * */

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector <int> v[2001];
bool chk[2001];
bool f = false;

void dfs(int x, int cnt){
    if(cnt==5){
        f = true;
        return;
    }

    chk[x] = true;

    for(int i=0; i<v[x].size(); i++){
        int nx = v[x][i];

        if(!chk[nx]) dfs(nx, cnt+1);
    }

    chk[x] = false;
}

void solve(){
    for(int i=0; i<N; i++){
        dfs(i, 1);
        if(f) break;
    }

    if(f) cout << 1;
    else cout << 0;
}

void input(){
    cin >> N >> M;

    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
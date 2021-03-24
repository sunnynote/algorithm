/**
 * 21-03-23
 * BOJ 4803 트리
 * */

#include <iostream>
#include <vector>
#include <cstring>
#define MX 500+2
using namespace std;

int N, M;
int ans = 0;
bool chk[MX];
bool visited[MX];
vector <int> v[MX];

int solveV(int idx){
    int cnt = 1;
    chk[idx] = true; 

    for(int i=0; i<v[idx].size(); i++){
        int nx = v[idx][i];
        if(!chk[nx])
            cnt += solveV(nx);
    }

    return cnt;
}

int solveE(int idx){
    int cnt = v[idx].size();
    visited[idx] = true;

    for(int i=0; i<v[idx].size(); i++){
        int nx = v[idx][i];
        if(!visited[nx])
            cnt += solveE(nx);
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int cnt = 0;
    while(1){
        cin >> N >> M;
        if(N==0 && M==0) break;
        
        ans = 0;
        memset(chk, 0, sizeof(chk));
        memset(visited, 0, sizeof(visited));

        for(int i=0; i<MX; i++)
            v[i].clear();

        int x, y;
        for(int i=0; i<M; i++){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        for(int i=1; i<=N; i++){
            if(!chk[i]){
                int V = solveV(i);
                int E = solveE(i);
                if(V-1 == E/2) ans++; // 트리 조건 성립
            }
        }

        cout << "Case " << ++cnt << ": ";
        if(ans==0){
            cout << "No trees.";
        }
        else if(ans==1){
            cout << "There is one tree.";
        }
        else{
            cout << "A forest of " << ans << " trees.";
        }
        cout << '\n';
    }

    return 0;
}
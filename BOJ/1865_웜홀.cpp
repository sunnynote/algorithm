/**
 * 20-10-02
 * BOJ 1865 웜홀
 * 벨만-포드
 * */

#include <iostream>
#include <vector>
#define INF 2e9
using namespace std;

struct Info{
    int x, y, w;
};

int N;
int dst[501];
vector <Info> adj;
string answer;

void solve(){
    dst[1] = 0;

    for(int i=1; i<N; i++){
        for(int j=0; j<adj.size(); j++){
            int from = adj[j].x;
            int to = adj[j].y;
            int cost = adj[j].w;

            if(dst[from]==INF) continue;
            if(dst[to]>dst[from]+cost) dst[to] = dst[from]+cost;
        }
    }

    for(int i=0; i<adj.size(); i++){
        int from = adj[i].x;
        int to = adj[i].y;
        int cost = adj[i].w;

        if(dst[from]==INF) continue;
        if(dst[to]>dst[from]+cost){ // warning!
            answer = "YES";
        }
    }

    cout << answer << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        // init
        answer="NO";
        adj.clear();

        int M, W;
        cin >> N >> M >> W;

        for(int i=0; i<M; i++){
            int x, y, w;
            cin >> x >> y >> w;
            adj.push_back({x,y,w});
            adj.push_back({y,x,w});
        }
        for(int i=0; i<W; i++){
            int x, y, w;
            cin >> x >> y >> w;
            adj.push_back({x,y,-w});
        }

        for(int i=0; i<N; i++)
            dst[i] = INF;

        solve();
    }

    return 0;
}

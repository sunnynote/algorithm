/**
 * 20-10-02
 * BOJ 11657 타임머신
 * 벨만-포드(1:N)
 * */

#include <iostream>
#include <vector>
#define INF 2e9
using namespace std;

struct Info{
    int x, y, w;
};

int N, M;
long long dist[502];
vector <Info> adj;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj.push_back({a,b,c});
    }

    for(int i=1; i<=N; i++)
        dist[i] = INF;

    dist[1]=0;
    for(int i=1; i<N; i++){ // N-1회 반복
        
        for(int j=0; j<adj.size(); j++){
            int from = adj[j].x;
            int to = adj[j].y;
            int cost = adj[j].w;

            if(dist[from]==INF) continue;
            
            if(dist[to] > dist[from]+cost) dist[to] = dist[from] + cost;
        }
    }

    bool endFlag = false;
    for(int i=0; i<adj.size(); i++){
        int from = adj[i].x;
        int to = adj[i].y;
        int cost = adj[i].w;

        if(dist[from]==INF) continue;
            
        if(dist[to] > dist[from]+cost) {
            cout << -1 << '\n';
            endFlag = true;
            break;
        }
    }

    if(!endFlag){
        for(int i=2; i<=N; i++){
            if(dist[i]==INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }

    return 0;
}

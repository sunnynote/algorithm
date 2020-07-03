/**
 * 200701
 * BOJ 9370 미확인 도착지
 * 다익스트라
 * */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

struct Node{
    int v, cost;
};
vector <Node> adj[2005];
vector <int> dist(2005, INF);
int cand[100];
vector <int> ans;

int N;

void dijk(int st){
    priority_queue <pair<int,int> > pq;
    for(int i=1; i<=N; i++)
        dist[i] = INF;
    

    dist[st] = 0;
    pq.push(make_pair(0, st));

    while(!pq.empty()){
        int cost = -pq.top().first;
        int from = pq.top().second;
        pq.pop();

        if(cost > dist[from]) continue;

        for(int i=0; i<adj[from].size(); i++){
            int to = adj[from][i].v;
            int nCost = cost + adj[from][i].cost;

            if(dist[to] > nCost){
                dist[to] = nCost;
                pq.push(make_pair(-nCost, to));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        int M, t;
        cin >> N >> M >> t;

        int S, G, H;;
        cin >> S >> G >> H;

        // init
        for(int i=1; i<=N; i++)
            adj[i].clear();
        ans.clear();

        for(int i=0; i<M; i++){
            int from, to, cost;
            cin >> from >> to >> cost;

            adj[from].push_back({to, cost});
            adj[to].push_back({from, cost});
        }

        for(int i=0; i<t; i++)
            cin >> cand[i];
        
        // s->e
        dijk(S);
        int sDist[2005];
        for(int i=1; i<=N; i++)
            sDist[i] = dist[i];

        // s->g->h->e
        dijk(G);
        int gDist[2005];
        int ghDist = dist[H];
        for(int i=1; i<=N; i++)
            gDist[i] = dist[i];

        // s->h->g->e
        dijk(H);
        int hDist[2005];
        for(int i=1; i<=N; i++)
            hDist[i] = dist[i];

        for(int i=0; i<t; i++){
            int dst = cand[i];
            if( (sDist[dst] == sDist[G] + ghDist + hDist[dst])
                || (sDist[dst] == sDist[H] + ghDist + gDist[dst]))
                    ans.push_back(dst);
        }

        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}
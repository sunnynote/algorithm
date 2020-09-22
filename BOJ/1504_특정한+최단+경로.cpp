/**
 * 200922
 *  BOJ 1504 특정한 최단경로
 *  다익스트라 or 그래프 특성
 * */

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector <pair<int,int> > adj[802];

vector <int> dijk(int startV){
    priority_queue <pair<int,int> > pq;
    vector <int> distance(802, INF);
    distance[startV] = 0;
    pq.push({0, startV});

    while(!pq.empty()){
        int cost = -pq.top().first;
        int from = pq.top().second;
        pq.pop();

        if(cost > distance[from]) continue;

        for(int i=0; i<adj[from].size(); i++){
            int to = adj[from][i].first;
            int d = adj[from][i].second;

            if(distance[to] > d+cost){
                distance[to] = d+cost;
                pq.push({-(d+cost), to});
            }
        }
    }

    return distance;
}

int main(){
    int N, E;
    cin >> N >> E;

    for(int i=0; i<E; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        
        adj[from].push_back({to, cost});
        adj[to].push_back({from, cost});
    }

    long long passA=0, passB=0;
    cin >> passA >> passB;

    long long res1=0, res2=0;

    vector<int> distS(802, INF);
    distS = dijk(1);
    res1 = distS[passA];
    res2 = distS[passB];

    vector<int> distA(802, INF);
    vector<int> distB(802, INF);
    distA = dijk(passA);
    distB = dijk(passB);

    res1 += distA[passB];
    res2 += distB[passA];

    res1 += distB[N];
    res2 += distA[N];

    if(res1>=INF && res2>=INF) cout << -1 << '\n';
    else if(res1<=res2) cout << res1 << '\n';
    else cout << res2 <<'\n';

    return 0;
}

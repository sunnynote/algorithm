/**
 * 20-10-05
 * BOJ 1446 지름길
 * 다익스트라
 * */

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, D;
int dist[10002];

vector <pair<int,int> > v[10002];

void dijk(){
    priority_queue <pair<int,int> > pq;
    dist[0] = 0;
    pq.push({0,0}); // cost, from

    while(!pq.empty()){
        int cost = -pq.top().first;
        int from = pq.top().second;
        pq.pop();

        for(int i=0; i<v[from].size(); i++){
            int to = v[from][i].first;
            int d = v[from][i].second;

            if(cost + d < dist[to]){
                dist[to] = cost+d;
                pq.push({-(cost+d), to});
            }
        }

        if(from+1 <= D && dist[from+1]>cost+1){
            dist[from+1] = cost+1;
            pq.push({-(cost+1), from+1});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> D;

    for(int i=0; i<N; i++){
        int from, to, d;
        cin >> from >> to >> d;
        v[from].push_back({to,d});
    }

    for(int i=0; i<=D; i++)
        dist[i] = INF;

    dijk();

    cout << dist[D];

    return 0;
}
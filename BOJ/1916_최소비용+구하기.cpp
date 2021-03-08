#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, M;
vector <pair<int, int> > v[1005];
int dist[1005];

void solve(int start){
    priority_queue <pair<int,int> > q;
    q.push(make_pair(0, start));
    dist[start] = 0;

    while(!q.empty()){
        int cost = -q.top().first;
        int x = q.top().second;
        q.pop();

        if(dist[x] < cost) continue;

        for(int i=0; i<v[x].size(); i++){
            int nx = v[x][i].first;
            int d = cost + v[x][i].second;

            if(dist[nx] > d){
                dist[nx] = d;
                q.push(make_pair(-d, nx));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    
    int x, y, cost;    
    for(int i=0; i<M; i++){
        cin >> x >> y >> cost;
        v[x].push_back(make_pair(y, cost));
    }

    for(int i=1; i<N+1; i++)
        dist[i] = INF;
    
    cin >> x >> y;
    solve(x);

    cout << dist[y];
    return 0;
}
/**
 * 200924
 * BOJ 2637 장난감 조립
 * 위상정렬
 * */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Info{
    int x, cnt;
};
vector <Info> v[102];
queue <int> q;
int in[102];

int res[102][102];

int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int x, y, k;
        cin >> x >> y >> k;
        v[y].push_back({x,k});
        in[x]++;
    }

    for(int i=1; i<=N; i++){
        if(!in[i]){
            q.push(i);
            res[i][i] = 1;
        }
    }

    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(int i=0; i<v[cur].size(); i++){
            int nx = v[cur][i].x;
            int ncnt = v[cur][i].cnt;

            for(int j=1; j<=N; j++){
                res[nx][j] += res[cur][j]*ncnt;
            }

            in[nx]--;
            if(!in[nx])
                q.push(nx);
        }
    }

    for(int i=1; i<=N; i++)
        if(res[N][i]) cout << i << ' ' << res[N][i] << '\n';
    
    return 0;
}
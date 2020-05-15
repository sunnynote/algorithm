#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, K, D;
int a[1005];
int res[1005];
int indegree[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        //init
        memset(a, 0, sizeof(a));
        memset(res, 0, sizeof(res));
        memset(indegree, 0, sizeof(indegree));
        vector <int> v[100005];
        queue <int> q;

        cin >> N >> K;
        for(int i=1; i<=N; i++)
            cin >> a[i];
        
        int from, to;
        for(int i=0; i<K; i++){
            cin >> from >> to;
            v[from].push_back(to); // from -> to
            indegree[to]++; // 진입 차수 증가
        }
        cin >> D;

        // 진입 차수 0인것 큐에 삽입
        for(int i=1; i<=N; i++){
            if(indegree[i]==0){
                q.push(i);
                res[i]=a[i];
            }
        }

        while(!q.empty()){
            int x = q.front();
            q.pop();

            // 간선 갯수 감소하고 진입차수 0인 것 큐에 삽입
            for(int i=0; i<v[x].size(); i++){
                int nx = v[x][i];
                --indegree[nx];
                if(indegree[nx]==0)
                    q.push(nx);
                
                // 최대 시간 갱신
                res[nx] = max(res[nx], res[x] + a[nx]);
            }
        }

        cout << res[D] << '\n';
    }
    
    return 0;
}
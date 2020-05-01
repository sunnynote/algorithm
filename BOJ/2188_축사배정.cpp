#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v[205];
int check[205];
int d[205];

bool dfs(int x){
    for(int i=0; i<v[x].size(); i++){
        int tmp = v[x][i]; // 방문할 곳

        if(check[tmp]) continue;
        check[tmp]=true;

        // 1. 아직 매칭 안됐거나
        // 2. 매칭되어 있지만, 다른 곳도 매칭할 수 있는지 확인
        if(d[tmp]==0 || dfs(d[tmp])){
            d[tmp] = x;
            return true;
        }
    }
    return false;
}

int main(){ㅁ
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        int n;
        cin >> n;

        for(int j=1; j<=n; j++){
            int t;
            cin >> t;
            v[i].push_back(t);
        }
    }

    int ans=0;
    for(int i=1; i<=N; i++){
        memset(check, 0, sizeof(check));
        if(dfs(i)) ans++;
    }

    cout << ans;
    return 0;
}
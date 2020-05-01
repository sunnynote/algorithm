#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
vector <int> v[1010];
int check[1010];
int d[1010];

bool dfs(int x){
    for(int i=0; i<v[x].size(); i++){
        int tmp = v[x][i];
        if(check[tmp]) continue;
        check[tmp]=true;
        if(d[tmp]==0 || dfs(d[tmp])){
            d[tmp]=x;
            return true;
        }
    }
    return false;
}

int main(){
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
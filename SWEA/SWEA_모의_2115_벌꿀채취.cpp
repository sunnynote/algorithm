#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int ans = 0;

int N, M, C;
int a[12][12];
bool check[12][12];

int sum, res;

void dfs(int x, int y, int cnt, int isC, int curSum){
    if(isC > C) return;

    res = max(res, curSum);

    if(cnt==M) return;

    dfs(x, y+1, cnt+1, isC+a[x][y], curSum+a[x][y]*a[x][y]);
    dfs(x, y+1, cnt+1, isC, curSum);
}

int func(int x, int y){
    for(int i=0; i<M; i++)
        check[x][y+i] = true;

    res = 0;
    dfs(x, y, 0, 0, 0);
    int honeyA = res;
    int honeyB = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<=N-M; j++){
            if(check[i][j]==0){
                res = 0;
                dfs(i, j, 0, 0, 0);
                honeyB = max(honeyB, res);
            }
        }
    }

    return honeyA + honeyB;
}

int main(int argc, char** argv){
    int test_case, T;
    cin >> T;

    for(test_case=1; test_case<=T; test_case++){
        cin >> N >> M >> C;
        memset(a, 0, sizeof(a));
        memset(check, 0, sizeof(check));

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin >> a[i][j];

        int ans = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<=N-M; j++)
                ans = max(ans, func(i,j));

        cout << '#' << test_case << ' ' << ans << '\n';
    }
    return 0;
}
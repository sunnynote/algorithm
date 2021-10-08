/**
 * 21-10-08
 * BOJ 1956 운동
 * 플로이드-와샬, 사이클
 * */

#include <iostream>
#define MX 987654321
using namespace std;

int V, E;
int arr[401][401];

void solve(){
    // 최단 경로 갱신
    for(int i=1; i<=V; i++)
        for(int j=1; j<=V; j++)
            for(int k=1; k<=V; k++)
                if(arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];

    // i-i의 경로 중 최소값
    int ans = MX;
    for(int i=1; i<=V; i++)
        if(ans > arr[i][i]) ans = arr[i][i];

    if(ans >= MX) ans = -1;
    cout << ans << '\n';
}

void input(){
    cin >> V >> E;

    for(int i=1; i<=V; i++)
        for(int j=1; j<=V; j++)
            arr[i][j] = MX;
    
    int a, b, c;
    for(int i=0; i<E; i++){
        cin >> a >> b >> c;
        arr[a][b] = c;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
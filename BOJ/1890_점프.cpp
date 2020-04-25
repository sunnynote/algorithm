#include <iostream>
#include <cstring>
using namespace std;

int N;
int map[105][105];
long long d[105][105];

int dx[2]={0,1};
int dy[2]={1,0};

long long dfs(int x, int y){
    if(x==N-1 && y==N-1) return 1; // 종료 조건

    if(d[x][y]!=-1) return d[x][y]; // 방문했다면 리턴
    if(map[x][y]==0) return 0; // 값이 0일 때 리턴

    if(!(0<=x && x<N && 0<=y && y<N)) return 0; // 범위 벗어나면 리턴

    long long res = 0;
    res += dfs(x + map[x][y], y);
    res += dfs(x, y + map[x][y]);

    d[x][y] = res;
    return res;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> map[i][j];
    
    memset(d, -1, sizeof(d));
    long long ans = dfs(0,0);
    cout << ans;
    return 0;
}
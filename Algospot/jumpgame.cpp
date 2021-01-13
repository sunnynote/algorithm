#include <iostream>
#include <cstring>
using namespace std;

int N;
int map[102][102];
int cache[102][102];

int solve(int x, int y){
    if(x>=N || y>=N) return 0;
    if(x==N-1 && y==N-1) return 1;

    int &ret = cache[x][y];
    if(ret!=-1) return ret;

    int jump = map[x][y];
    ret = (solve(x+jump, y) || solve(x, y+jump));

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        cin >> N;

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin >> map[i][j];

        memset(cache, -1, sizeof(cache));
        int ans = solve(0, 0);

        if(ans==1) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    
    return 0;
}
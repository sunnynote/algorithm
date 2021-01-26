/**
 * 21-01-20
 * 동적계획법
 * */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int map[102][102];
int sum[102][102];
int cache[102][102];

int pathSum(int x, int y){
    if(x==N-1) return map[x][y];

    int &ret = sum[x][y];
    if(ret != -1) return ret;

    ret = max(pathSum(x+1, y), pathSum(x+1, y+1)) + map[x][y];

    return ret;
}

int solve(int x, int y){
    if(x==N-1) return 1;

    int &ret = cache[x][y];
    if(ret != -1) return ret;

    // ret = 0;
    if(pathSum(x+1, y) > pathSum(x+1, y+1)){
        ret = solve(x+1, y);
    }
    else if(pathSum(x+1, y) < pathSum(x+1, y+1)){
        ret = solve(x+1, y+1);
    }
    else {
        ret = solve(x+1, y) + solve(x+1, y+1);
    }
    // ret = max(solve(x+1, y), solve(x+1, y+1)) + map[x][y];

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    
    while(T--){
        memset(sum, -1, sizeof(sum));
        memset(cache, -1, sizeof(cache));

        cin >> N;
        for(int i=0; i<N; i++)
            for(int j=0; j<=i; j++)
                cin >> map[i][j];
        
        cout << solve(0,0) << '\n';
    }

    return 0;
}
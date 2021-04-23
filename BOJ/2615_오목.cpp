/**
 * 21-04-21
 * BOJ 2615 오목
 * BF
 */

#include <iostream>
using namespace std;

int arr[22][22];
bool chk[22][22][4];

int dx[4]={0,-1,1,1};
int dy[4]={1,1,0,1};

bool f = false;

void solve(int x, int y){
    for(int i=0; i<4; i++){
        int cnt = 0;
        
        for(int j=0; j<5; j++){
            int nx = x + dx[i]*j;
            int ny = y + dy[i]*j;

            if(!(0<nx && nx<=19 && 0<ny && ny<=19)) continue;
            if(arr[x][y] != arr[nx][ny]) break;
            cnt++;
        }

        if(cnt==5){
            if(0<x-dx[i] && 0<y-dy[i])
                if(arr[x][y] == arr[x-dx[i]][y-dy[i]]) continue;

            if(x+dx[i]*5<=19 && y+dy[i]*5<=19)
                if(arr[x][y] == arr[x+dx[i]*5][y+dy[i]*5]) continue;

            cout << arr[x][y] << '\n';
            cout << x << ' ' << y << '\n';
            
            f = true;
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for(int i=1; i<=19; i++)
        for(int j=1; j<=19; j++)
            cin >> arr[i][j];

    for(int i=1; i<=19; i++){
        for(int j=1; j<=19; j++){
            if(arr[i][j]!=0)
                solve(i, j);

            if(f) break;
        } if(f) break;
    }

    if(!f) cout << 0;

    return 0;
}